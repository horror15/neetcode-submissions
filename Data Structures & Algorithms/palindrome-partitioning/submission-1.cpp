class Solution {
public:
    bool palin(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void test(string s, int start, vector<string>& vec, vector<vector<string>>& out){
        if(start == s.size()){
            out.push_back(vec);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(palin(s, start, i)){
                vec.push_back(s.substr(start, i-start+1));
                test(s, i+1, vec, out);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>vec;
        vector<vector<string>>out;
        test(s, 0, vec, out);
        return out;
    }
};
