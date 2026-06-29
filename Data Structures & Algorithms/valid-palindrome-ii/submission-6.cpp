class Solution {
public:
    bool ispalin(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(s[i+1] == s[j]){
                    if(ispalin(s, i+1, j)) return true;
                } 
                if(s[i] == s[j-1]){
                    if(ispalin(s, i, j-1)) return true;
                } 
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};