class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>vec(26, 0);
        priority_queue<int>pq;
        for(int i=0; i<tasks.size(); i++){
            	vec[tasks[i]-'A'] += 1;
        }
        for(int i=0; i<vec.size(); i++){
            if(vec[i]>0){
                pq.push(vec[i]);
            }
        }
        queue<pair<int, int>>q;
        int time = 0;
        //{next_time, count}
        while(!pq.empty() || !q.empty()){
            if(!q.empty()){
                if(q.front().first == time){
                    pq.push(q.front().second);
                    q.pop();
                }
            }
            if(!pq.empty()){
                int p = pq.top();
                pq.pop();
                p--;
                if(p>0){
                    q.push({time+n+1, p});
                }
            }
            time++;
        }
        return time;
    }
};
