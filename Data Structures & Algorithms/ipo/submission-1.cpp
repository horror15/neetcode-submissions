class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;
        int size = 0;
        while(size < profits.size()) {
            vec.push_back({capital[size], profits[size]});
            size++;
        }
        sort(vec.begin(), vec.end());
        int projects = 1;
        int index = 0;
        priority_queue<int>pq;
        while (projects <= k) {
            while(index < vec.size()){
                if(vec[index].first <= w){
                    pq.push(vec[index].second);
                    index++;
                } else {
                    break;
                }
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
            projects++;
        }
        return w;
    }
};