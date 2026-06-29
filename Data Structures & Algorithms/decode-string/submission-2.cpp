class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        string str = "";
        for(auto ch:s){
            if(ch == ']'){
                string test ="";
                while(!st.empty() && st.top()!='['){
                    test = st.top() + test;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && st.top() - '0' <= 9 && st.top() - '0' >= 0){
                    num = st.top() + num;
                    st.pop();
                }
                int n = stoi(num);
                string out = "";
                for(int i=0; i<n; i++){
                    out += test; 
                }
                for(auto t:out){
                    st.push(t);
                }
            } else {
                st.push(ch);
            }
        }
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};