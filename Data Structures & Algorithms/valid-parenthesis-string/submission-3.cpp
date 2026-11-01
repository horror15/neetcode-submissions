class Solution {
public:
    bool checkValidString(string s) {
        stack<int>s1;
        stack<int>s2;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                s1.push(i);
            } else if(s[i]=='*'){
                s2.push(i);
            } else{
                if(s1.empty() && s2.empty()){
                    return false;
                } else if(s1.empty() && !s2.empty()){
                    s2.pop();
                } else{
                    s1.pop();
                }
            
            }
        }
        if(!s1.empty()){
            while(!s1.empty()){
                if(s2.empty()) return false;
                int s = s1.top();
                if(s>s2.top()) return false;
                s1.pop();
                s2.pop();
            }
        }
        return true;
    }
};
