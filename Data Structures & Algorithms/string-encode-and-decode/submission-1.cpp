class Solution {
public:

    string encode(vector<string>& strs) {
        string en_code = "";
        for(int i=0; i<strs.size(); i++){
            en_code += to_string(strs[i].size() ) + ":" + strs[i];
        }
        return en_code;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int j=0;
        while(j<s.size()){
            if(s[j] == ':'){
                int sz = stoi(s.substr(i, j-i));
                res.push_back(s.substr(j+1, sz));
                j += 1+sz;
                i=j;
            } else {
                j++;
            }
        }
        return res;
    }
};
