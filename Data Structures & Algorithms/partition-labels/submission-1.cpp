class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;
        vector<int>vec;
        for(int i=0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        int j=0, i=0, count=0;
        while(i<s.size()){
            if(i>j){
                vec.push_back(count);
                count=0;
            }
            j = max(mp[s[i]], j);
            count++;
            i++;
        }
        if(i>j){
            vec.push_back(count);
        }
        return vec;
    }
};
