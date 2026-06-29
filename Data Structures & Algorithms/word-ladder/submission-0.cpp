class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>word;
        for(auto it: wordList){
            word.insert(it);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        word.erase(beginWord); 
        while (!q.empty()){
            string ss = q.front().first;
            int size = q.front().second;
            if(ss == endWord) return size;
            q.pop();
            for(int i=0; i<ss.size(); i++){
                string st = ss;
                for(int j=0; j<26; j++){
                    char c = j+'a';
                    st[i] = c;
                    if(word.find(st) != word.end()){
                        word.erase(st);
                        q.push({st, size+1});
                    }
                }
            }
        }
        return 0;
    }
};
