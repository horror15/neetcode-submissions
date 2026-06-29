class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1) return 1;
        int count=0;
        for(int i=0; i<s.size(); i++){
            int l = i;
            int r = i;
            while(l>-1 && r<s.size() && s[l] == s[r]){
                l--;
                r++;
                count++;
            }
            l=i-1;
            r=i;
            while(l>-1 && r<s.size() && s[l] == s[r]){
                l--;
                r++;
                count++;
            }
        }
        return count;
    }
};
