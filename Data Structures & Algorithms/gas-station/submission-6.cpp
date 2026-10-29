class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0, total_cost=0;
        for(int i=0; i<gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_gas<total_cost){
            return -1;
        }
        int gas_left = 0, index=0;
        for (int i=0; i<gas.size(); i++){
            gas_left += gas[i];
            if(gas_left < cost[i]){
                gas_left = 0;
                index = i+1;
            } else {
                gas_left -= cost[i];
            }
        }
        return index;
    }
};
