class MinStack {
public:
    int mini = INT_MAX;
    stack<pair<int, int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int, int>p;
        p.first = val;
        mini = min(mini, val);
        p.second = mini;
        s.push(p);
    }
    
    void pop() {
        s.pop();
        if(!s.empty()){
            mini = s.top().second;
        } else {
            mini = INT_MAX;
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
