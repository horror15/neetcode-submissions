class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
                vector<int>vec(26, 0);
                for (auto t:tasks){
                        vec[t-'A'] += 1;
                }
                priority_queue<int>pq;
                for (auto freq: vec){
                        if(freq>0){
                             pq.push(freq);   
                        }
                }
                int total_cycles = (pq.top()-1)*n+pq.top();
                int max_freq = pq.top();
                pq.pop();
                while(!pq.empty() && max_freq == pq.top()){
                        total_cycles+=1;
                        pq.pop();
                }
                return max(int(tasks.size()), total_cycles);
        }
};