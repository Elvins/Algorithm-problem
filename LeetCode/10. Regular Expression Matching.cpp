/**
10. Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
**/

/*
'.' 对应一个字符.
'*' 对应零个或多个的前一个字符.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        return matchRegularExpression(s.c_str(), p.c_str());
    }
    
private:
    bool matchRegularExpression(const char *s, const char *p){
        //空指针
        if(s == NULL || p == NULL){
            return false;
        }
        //当p为空串时，s为空串才为true
        if (*p == '\0'){
            return *s == '\0';
        }
        //后一位不是*时
        if(*(p+1) != '*'){
            //s不为空串,其匹配正确
            if((*p == *s) || (*p == '.' && *s != '\0')){
                return matchRegularExpression(s+1, p+1);
            }
        }else{
            // *s == *p  
            while ((*p == *s) || (*p == '.' && *s != '\0'))  
            {  
                if (matchRegularExpression(s, p+2)){
                    return true;
                }
                s++;
            }
            return (matchRegularExpression(s, p+2));
        }
		return false;
    }
};