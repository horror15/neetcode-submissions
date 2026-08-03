class Solution {
public:
    void test(string s, vector<string>& wordDict, unordered_set<string> &st, vector<string>& ss, vector<string>& out, int start){
        if(start == s.size()){
            string final = "";
            for(int i=0; i<ss.size()-1; i++){
                final += ss[i] + " ";
            }
            final += ss[ss.size()-1];
            out.push_back(final);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string str = s.substr(start, i-start+1);
            if(st.find(str) != st.end()){
                ss.push_back(str);
                test(s, wordDict, st, ss, out, i+1);
                ss.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        vector<string> ss;
        vector<string> out;
        test(s, wordDict, st, ss, out, 0);
        return out;
    }
};