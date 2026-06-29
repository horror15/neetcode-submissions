class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>>mp;
        vector<vector<string>>result;
        for(int i=0; i<strs.size(); i++){
            vector<int>vec(26, 0);
            for(int j=0; j<strs[i].size(); j++){
                vec[strs[i][j] - 'a'] += 1;
            }
            mp[vec].push_back(strs[i]);
        }
        for(auto [key, val]:mp){
            result.push_back(val);
        } 
        return result;
    }  
};
