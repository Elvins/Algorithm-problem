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
        int i = 0, j = 0; //i是候选字符串的起点， j是候选字符串的终点。  
        int max_len = 0;  
        int cur_len = 0;  
        bool isExist[256] = { false };  
        while (j < len) {  
            if (!isExist[s[j]]) {
                //遍历过，记录为true
                isExist[s[j]] = true;
                j++;  
            } else {  
                while(s[i]!= s[j]) {  
                    isExist[s[i]] = false;   
                    //新候选字串从第一个重复字符(当s[i] == s[j]时候的i)的后一位开始算，之前的i不算，等效于没有被扫描到，所以设为false.  
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