class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<int> vec;
        for(int i=0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        int i=0;
        int j=-1;
        int count = 0;
        while(i<s.size()) {
            int k = mp[s[i]];
            if(k>j){
                j=k;
            }
            if(i<j){
                i++;
                count++;
            } else {
                count++;
                vec.push_back(count);
                count = 0;
                i++;
            }
        }
        return vec;
    }
};
