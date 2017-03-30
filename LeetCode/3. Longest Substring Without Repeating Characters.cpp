/**
3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
**/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();  
        int i = 0, j = 0; //i�Ǻ�ѡ�ַ�������㣬 j�Ǻ�ѡ�ַ������յ㡣  
        int max_len = 0;  
        int cur_len = 0;  
        bool isExist[256] = { false };  
        while (j < len) {  
            if (!isExist[s[j]]) {
                //����������¼Ϊtrue
                isExist[s[j]] = true;
                j++;  
            } else {  
                while(s[i]!= s[j]) {  
                    isExist[s[i]] = false;   
                    //�º�ѡ�ִ��ӵ�һ���ظ��ַ�(��s[i] == s[j]ʱ���i)�ĺ�һλ��ʼ�㣬֮ǰ��i���㣬��Ч��û�б�ɨ�赽��������Ϊfalse.  
                    i++;  
                }  
                i++;  
                j++;  
            }  
            cur_len = j - i;  
            max_len = max_len > cur_len ? max_len : cur_len;  
        }  
        return max_len;  
    }
};