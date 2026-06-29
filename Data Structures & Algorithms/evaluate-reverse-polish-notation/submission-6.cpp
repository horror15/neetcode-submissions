class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto st: tokens){
            if(st == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            } else if(st == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            } else if(st == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            } else if(st == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            } else{
                s.push(stoi(st));
            }
        }
        return s.top();
    }
};
