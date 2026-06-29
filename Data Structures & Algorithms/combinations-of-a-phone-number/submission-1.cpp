class Solution {
public:
    void backtrack(vector<string> &output, string &digits, unordered_map<char, string>&mp, int index, string letter) {
        if(index == digits.size()){
            output.push_back(letter);
            return;
        }
        string current = mp[digits[index]];
        for (int i=0; i<current.size(); i++){

            backtrack(output, digits, mp, index+1, letter + current[i]);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        unordered_map<char, string>mp;
        mp = {
            {'2' ,"abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };
        if(digits == ""){
            return output;
        }
        string letter = "";
        backtrack(output, digits, mp, 0, letter);
        return output;
    }
};
