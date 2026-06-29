class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        int i=0;
        int s = min(s1, s2);
        string str = "";
        while(i<s){
            str += word1[i];
            str += word2[i];
            i++;
        }
        if(s1>s2){
            while(i<s1){
                str += word1[i];
                i++;
            }
        } else {
            while(i<s2){
                str += word2[i];
                i++;
            }
        }
        return str;

    }
};