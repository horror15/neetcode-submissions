class FreqStack {
public:
    int max_freq = 0;
    unordered_map<int, int>mp;
    unordered_map<int, stack<int>>st;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val] += 1;
        max_freq = max(max_freq, mp[val]);
        st[mp[val]].push(val);
    }
    
    int pop() {
        int val = st[max_freq].top();
        mp[st[max_freq].top()] -= 1;
        st[max_freq].pop();
        if(st[max_freq].empty()){
            max_freq -= 1;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */