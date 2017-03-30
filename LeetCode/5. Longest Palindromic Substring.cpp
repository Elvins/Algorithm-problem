/**
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"
**/

//动态规划
/*
定义：
P[ i, j ] ← true ，如果从i开始到j的字串为回文串
状态转移方程：
P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj ) 
显然，如果一个子串是回文串，并且如果从它的左右两侧分别向外扩展的一位也相等，那么这个子串就可以从左右两侧分别向外扩展一位。

其中的base case是
P[ i, i ] ← true，长度为1
P[ i, i+1 ] ← ( Si = Si+1)，长度为2
*/ 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int beginPtr = 0;
        int maxLen = 1;
        bool P[1000][1000] = {false};
        for (int i = 0; i < n; i++){
            P[i][i] = true;
        }
        for (int i = 0; i < n-1; i++){
            if (s[i] == s[i+1]) {
                P[i][i+1] = true;
                beginPtr = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; len++){
            for (int i = 0; i < n-len+1; i++){
                int j = i+len-1;
                if (s[i] == s[j] && P[i+1][j-1]){
                    P[i][j] = true;
                    beginPtr = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(beginPtr, maxLen);
    }
};


//方法2
class Solution2 {
public:
    // 转换 S -> T.
    // 如： S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ 标记字符串的头尾
   string preProcess(string s){
        int n = s.length();
        if (n == 0) return "^$";

        string ret = "^";
        for (int i = 0; i < n; i++){
            ret += "#" + s.substr(i, 1);
        }
        
        ret += "#$";
        return ret;
    }
	
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int length = T.length();
        int* p = new int[length];
        int C = 0, R = 0;
        
        for (int i = 1; i < length - 1; i++){
            int i_mirror = C - (i - C);
            int diff = R - i;
            if (diff >= 0)//当前i在C和R之间，可以利用回文的对称属性
            {
				//i的对称点的回文长度在C的大回文范围内部
                if (p[i_mirror] < diff){
					p[i] = p[i_mirror];
				}else{
                    p[i] = diff;
                    //i处的回文可能超出C的大回文范围了
                    while (T[i + p[i] + 1] == T[i - p[i] - 1]){ 
						p[i]++;
					}
                    C = i;
                    R = i + p[i];
                }
            }else{
                p[i] = 0;
                while (T[i + p[i] + 1] == T[i - p[i] - 1]){
					p[i]++;
				}
                C = i;
                R = i + p[i];
            }
        }

        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < length - 1; i++) {
            if (p[i] > maxLen){
              maxLen = p[i];
              centerIndex = i;
            }
        }
        return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);        
    }
};
