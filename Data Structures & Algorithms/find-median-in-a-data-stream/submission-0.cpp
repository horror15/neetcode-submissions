class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        int top = left.top();
        left.pop();
        right.push(top);
        if (right.size() > left.size()){
            int top = right.top();
            left.push(top);
            right.pop();
        }
    }
    
    double findMedian() {
        int size = left.size() + right.size();
        if(size%2 != 0){
            return (double)left.top();
        }
        double mid = (left.top() + right.top())/2.0;
        return mid;
    }
};
