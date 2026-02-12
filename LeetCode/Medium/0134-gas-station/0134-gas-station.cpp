// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int totalSum = 0;
//         int curSum = 0;
//         int start = 0;

//         for (int i = 0; i < gas.size(); i++) {
//             totalSum += gas[i] - cost[i];
//             curSum += gas[i] - cost[i];

//             if (curSum < 0) {
//                 start = i + 1;
//                 curSum = 0;
//             }
//         }

//         if (totalSum < 0)
//             return -1;
//         return start;
//     }
// };


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < cost.size(); i++) {
            int rest = gas[i] - cost[i]; // Track remaining gas
            int index = (i + 1) % cost.size();
            while (rest > 0 && index != i) { // Simulate starting at i for one lap (if rest==0, the solution is not unique)
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            // If starting at i for one lap, gas remaining >=0, return the starting position
            if (rest >= 0 && index == i) return i;
        }
        return -1;
    }
};