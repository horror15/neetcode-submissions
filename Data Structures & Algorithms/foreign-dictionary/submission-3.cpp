class Solution {
public:

    string foreignDictionary(vector<string>& words) {
        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        for(auto w: words){
            for(auto ch: w){
                present[ch-'a'] = true;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            int j = 0;
            int k = 0;
            bool found = false;
            //if(words[i].size() > words[i+1].size()) return "";
            while (j < words[i].size() && k < words[i+1].size()){
                if(words[i][j] != words[i+1][k]){
                    adj[words[i][j] - 'a'].insert(words[i+1][k] - 'a');
                    //indegree[words[i+1][k] - 'a']++;
                    found = true;
                    break;
                }
                j++;
                k++;
            }
            if(!found && words[i].size() > words[i+1].size()) return "";
        }

        for(int i=0; i<26; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<26; i++){
           if(indegree[i] == 0 && present[i]){
                q.push(i);
           }
        }
        string st = "";
        while(!q.empty()){
            int p = q.front();
            q.pop();
            st += p+'a';
            for(auto it: adj[p]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        for(int i=0; i<26; i++){
            if(present[i] && indegree[i]!=0){
                return "";
            }
        }
        return st;
    }
};
