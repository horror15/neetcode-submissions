class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        stack<char>s2;
        for(auto st:s){
            s1.push(st);
        }
        while(!s1.empty()){
            char c = s1.top();
            if(c==')' || c==']' || c=='}'){
                s2.push(c);
                s1.pop();
            } else {
                if(s2.empty()){
                    return false;
                }
                while(!s2.empty() && !s1.empty()){
                    if(s2.top() == ')' && s1.top() != '('){
                        return false;
                    }
                    if(s2.top() == '}' && s1.top() != '{'){
                        return false;
                    } 
                    if(s2.top() == ']' && s1.top() != '['){
                        return false;
                    }
                    s1.pop();
                    s2.pop();
                }
            }
        }
        if(!s2.empty()){
            return false;
        }
        return true;

    }
};
