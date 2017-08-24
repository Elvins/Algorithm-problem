/**
Write a function to find the longest common prefix string amongst an array of strings.
**/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
        string res;        
        if (strs.size() == 0)
            return res;        
        sort(strs.begin(), strs.end());
        char c;
        for (int k = 0; k < strs[0].size(); ++k) {
            c = strs[0][k];
            for (int i = (int) strs.size() - 1; i > 0; --i) {
                if (c != strs[i][k])
                    return res;
            }
            res += c;
        }
        return res;
    }
};
