class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int>vec(26,0);
        for(int i=0; i<s.size(); i++){
            vec[s[i] - 'a'] += 1; 
        }
        for(int i=0; i<t.size(); i++){
            if(vec[t[i]-'a'] == 0){
                return false;
            }
            vec[t[i]-'a'] -= 1;
        }
        return true;

    }
};
