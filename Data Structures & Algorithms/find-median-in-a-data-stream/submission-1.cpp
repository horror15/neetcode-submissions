class MedianFinder {
public:
    priority_queue<int>pq_left;
    priority_queue<int, vector<int>, greater<int>>pq_right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq_left.empty() && pq_right.empty()){
            pq_left.push(num);
        } else if (num>pq_left.top()){
            pq_right.push(num);
        } else {
            pq_left.push(num);
        }
        if(abs((int)pq_left.size() - (int)pq_right.size())>1){
            if(pq_left.size()>pq_right.size()){
                pq_right.push(pq_left.top());
                pq_left.pop();
            } else{
                pq_left.push(pq_right.top());
                pq_right.pop();
            }
        }
    }
    
    double findMedian() {
        if(pq_left.size()==pq_right.size()){
            return (float)(pq_left.top() + pq_right.top())/2;
        } else if(pq_left.size()>pq_right.size()){
            return pq_left.top();
        } else{
            return pq_right.top();
        }
    }
};
