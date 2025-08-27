class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int rep = cost.size();
        for(int i = 2; i < rep; i++){
            cost[i] += std::min(cost[i-1], cost[i-2]); // always take the min path, like with dijkstra 

        }
        return std::min(cost[rep-1], cost[rep-2]);
    }
};