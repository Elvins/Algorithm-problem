/**
126. Word Ladder II
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
**/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> used_words;
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1;
        while(!paths.empty()){
            auto path = paths.front();
            paths.pop();
            if(path.size() > level){
                level = (int) path.size();
                for(string w: used_words){
                    dict.erase(w);
                }
                used_words.clear();
                if(dict.empty())
                    break;
            }
            auto lastWord = path.back();
            for(int i = 0; i < lastWord.length(); i++){
                string temp = lastWord;
                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;
                    if(!dict.count(temp))
                        continue;
                    used_words.insert(temp);
                    vector<string> next = path;
                    next.push_back(temp);
                    if (temp == endWord) {
                        result.push_back(next);
                    } else {
                        paths.push(next);
                    }
                }
            }
        }
        return result;
    }
};
