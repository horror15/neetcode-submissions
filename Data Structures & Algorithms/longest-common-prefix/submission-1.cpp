#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for(int i=0; i<strs[0].length();i++)
        {
            for(int j=0; j<strs.size();j++)
            {
                if (i == strs[j].length() || strs[0][i] != strs[j][i])
                {
                    return res;
                } 
            }
            res = res + strs[0][i];
        }

        return res;

            

    }
};