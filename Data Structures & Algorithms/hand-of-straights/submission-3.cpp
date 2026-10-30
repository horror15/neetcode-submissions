class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();
        if(n%groupSize!=0) return false;
        unordered_map<int, int>mp;
        for(int i=0; i<hand.size(); i++){
            mp[hand[i]] += 1;
        }
        for(int i=0; i<hand.size(); i++){
            int card = hand[i];
            if(mp[card]==0) continue;
            int count = mp[card];
            for(int j=0; j<groupSize; j++){
                int s_card = card+j;
                if(mp[s_card]<count) return false;
                mp[s_card] -= count;
            }
        }
        return true;
    }
};
