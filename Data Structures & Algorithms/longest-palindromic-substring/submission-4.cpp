class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        string res = "";
        for(int i=1; i<s.size(); i++){
            int l = i;
            int r = i;
            while(l>-1 && r<s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            string p = s.substr(l+1, r-l-1);
            if(p.size() > res.size()){
                res = p;
            }
            l = i-1;
            r = i;
            while(l>-1 && r<s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            p = s.substr(l+1, r-l-1);
            if(p.size() > res.size()){
                res = p;
            }
            
        }

        return res;

    }
};
