class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for(int i=0; i<s.size(); i++){
            if(tolower(s[i])-'a'>=0 && tolower(s[i])-'a' < 26){
                st += tolower(s[i]);
            }
            if(s[i] - '0' >=0 && s[i] - '0' <10){
                st += tolower(s[i]);
            }
        }
        cout<<st;
        int i=0, j=st.size()-1;
        while(i<j){
            if(st[j]!=st[i]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
