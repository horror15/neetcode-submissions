class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int i=0;i<strs[0].size();i++){
        //char c = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if (strs[j][i]!=strs[0][i]){
                    return res;
                }
            }
            res = res + strs[0][i];
        }
        return res;
    }
};