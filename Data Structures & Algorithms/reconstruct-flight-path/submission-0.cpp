class Solution {
public:
    void backtrack(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>  &adj, vector<string> &result, string st){

        while(adj.count(st) && !adj[st].empty()){
            string tmp = adj[st].top();
            adj[st].pop();
            backtrack(adj, result, tmp);
        }
        result.push_back(st);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        vector<string> result;
        for(int i=0; i<tickets.size(); i++){
            adj[tickets[i][0]].push(tickets[i][1]);
        }
        backtrack(adj, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
