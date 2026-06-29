class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        int i=0, j=s1.size()-1;
        vector<int>string1(26,0);
        vector<int>string2(26,0);

        for(auto ch:s1){
            string1[ch-'a'] += 1;
        }
        for(int i=0; i<s1.size(); i++){
            string2[s2[i]-'a'] += 1;
        }
        if(string1 == string2){
            return true;
        }
        j++;
        while(j<s2.size()){
            string2[s2[i] - 'a'] -= 1;
            string2[s2[j] - 'a'] += 1;
            i++;
            j++;
            if(string1 == string2){
                return true;
            }
        }
        return false;
    }
};
