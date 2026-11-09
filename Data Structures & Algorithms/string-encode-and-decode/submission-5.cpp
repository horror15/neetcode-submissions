class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(const auto& str: strs){
            int len = str.size();
            s += to_string(len) + "," + str; 
        }
        //cout<<s;
        return s;
    }

    vector<string> decode(string s) {
        vector<string>out;
        int i=0, j=0;
        while(j<s.size()){
            if(s[j] != ','){
                j++;
            } else {
                int len = stoi(s.substr(i, j-i));
                string st = s.substr(j+1, len);
                out.push_back(st);
                j = j + len+1;
                i=j;
            }
        }
        return out;
    }
};
