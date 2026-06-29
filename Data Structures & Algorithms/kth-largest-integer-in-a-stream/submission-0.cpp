class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>p;
    int size = 0;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto num: nums){
            p.push(num);
            if(p.size()>k){
                p.pop();
            }
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>size){
            p.pop();
        }
        return p.top();
    }
};
