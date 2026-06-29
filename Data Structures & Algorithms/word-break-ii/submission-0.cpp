class Solution {
public:
    void backtrack(string &s, vector<string> &result, int start, vector<string> &path, unordered_set<string> &hs){

        if(start == s.size()){
            string final = "";
            for(int i=0; i<path.size()-1; i++){
                final += path[i] + " "; 
            }
            final += path[path.size()-1];
            result.push_back(final);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string word = s.substr(start, i-start+1);
            if(hs.find(word) != hs.end()){
                path.push_back(word);
                backtrack(s, result, i+1, path, hs);
                path.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<string> path;
        unordered_set<string> hs;
        for(string word: wordDict){
            hs.insert(word);
        }
        backtrack(s, result, 0, path, hs);
        return result;
    }
};