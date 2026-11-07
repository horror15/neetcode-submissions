class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(const auto& s:strs){
            vector<int>vec(26, 0);
            for(const auto& c:s){
                vec[c-'a'] += 1;
            }
            string key = "";
            for(int i=0; i<26; i++){
                key += to_string(vec[i]) + ',';
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto& pair: mp){
            result.push_back(pair.second);
        }
        return result;
    }
};
