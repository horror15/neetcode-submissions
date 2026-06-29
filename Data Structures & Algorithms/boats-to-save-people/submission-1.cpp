class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, weight=0, count=0, j=people.size()-1;
        while(i<j){
            weight += people[i] + people[j]; 
            if(weight < limit){
                i++;
            } else if(weight > limit){
                j--;
                weight = 0;
                count++;
            } else{
                i++;
                j--;
                weight=0;
                count++;
            }

        }
        if(i==j){
            count++;
        }
        return count;

    }
};