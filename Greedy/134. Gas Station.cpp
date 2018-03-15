/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, tank = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
            if ((tank = tank + gas[i] - cost[i]) < 0) { // 油不够，需要重设起点
                total += tank; // 记录这一段路程的净损耗
                tank = 0;
                start = i + 1;
            }
        }
        return (tank + total) < 0 ? -1 : start;
    }
};