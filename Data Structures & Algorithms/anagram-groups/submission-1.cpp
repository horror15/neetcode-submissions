class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<vector<int>, vector<string>>mp;
            vector<vector<string>> str;
            for (int i=0; i<strs.size(); i++){
                vector<int> vec(26, 0);
                for(int j=0; j<strs[i].size(); j++){
                    int index = strs[i][j] - 'a';
                    vec[index] += 1; 
                }
                mp[vec].push_back(strs[i]);
            }
            for (const auto& pair : mp) {
                str.push_back(pair.second);
            }
            return str;
    }
};
