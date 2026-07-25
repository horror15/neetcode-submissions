class Solution {
public:
    void test(string digits, unordered_map<char, string>& mp, int start, string& str, vector<string>& out){
        if(start == digits.size()) {
            out.push_back(str);
            return;
        }
        char ch = digits[start];
        for(int j=0; j<mp[ch].size(); j++){
            str += mp[ch][j]; 
            test(digits, mp, start+1, str, out);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char, string>mp;
        mp = {{'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}};
        string str = "";
        vector<string>out;
        test(digits, mp, 0, str, out);
        return out;
    }
};
