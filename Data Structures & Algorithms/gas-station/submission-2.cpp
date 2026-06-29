class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_left = 0;
        int index = 0;
        int total_gas = 0;
        int total_price = 0;
        for(int i=0; i<gas.size(); i++){
            total_gas += gas[i];
        }
        for(int i=0; i<cost.size(); i++){
            total_price += cost[i];
        }
        for(int i=0; i<gas.size(); i++){
            gas_left += gas[i];
            if(gas_left >= cost[i]){
                gas_left -= cost[i];
            } else {
                index = i+1;
                gas_left = 0;
            } 
        }
        for(int i=index; i<gas.size(); i++){
            total_gas -= gas[i]; 
        }
        total_gas += gas_left;
        for(int i=index; i<cost.size(); i++){
            total_price -= cost[i]; 
        }
        if(total_gas>=total_price) return index;
        return -1;
    }
};
