class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;
        for (auto ch:s){
            mp[ch] += 1;
        }
        for (auto ch:t){
            if(mp.find(ch) == mp.end()){
                return false;
            } else {
                mp[ch] -= 1;
                if (mp[ch] == 0){
                    mp.erase(ch);
                }
            }
        }
        if (mp.empty()){
            return true;
        } else{
            return false;
        }
    }
};
