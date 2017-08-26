
/**
93. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
**/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        dfs(s, 0, 0, "", results);
        return results;
    }
    
    void dfs(string& s, int index, int segments, string result, vector<string>& results) {
        if(index == s.size()) {
            if(segments == 4) {
                result.pop_back();
                results.push_back(result);
            }
            return;
        }
        if(segments >= 4)  return;
        
        dfs(s, index + 1, segments + 1, result + s[index] + ".", results);
        if(s[index] != '0' && index + 1 < s.size()) {
            dfs(s, index + 2, segments + 1, result + s[index] + s[index+1] + ".", results);
        }
        if(index + 2 < s.size()) {
            if((s[index] == '1') || (s[index] == '2' && (s[index+1] <= '4' || (s[index+1] == '5' && s[index+2] <= '5')))) {
                dfs(s, index + 3, segments + 1, result + s[index] + s[index+1] + s[index+2] + ".", results);
            }
        }
    }
};
