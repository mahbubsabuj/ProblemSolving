class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int) gas.size();
        int total_gas = 0, total_cost = 0;
        for (int i = 0; i < n; ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_gas < total_cost) return -1;
        int sum = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                idx = i + 1;
                sum = 0;
            }
        }
        return idx;
    }
};