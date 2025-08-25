class Solution {
public:


    int climbStairs(int n) {   
        std::unordered_map<int,int> dp;     
        return climb(n, dp);


    }
    int climb(int n, std::unordered_map<int,int>& dp){
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp.find(n) == dp.end()){
            // Already existed use them so we don't have to redo the recursion
            dp[n] = climb(n-1, dp) + climb(n-2, dp); // Because the previous step could be a +1 or +2
        }

        return dp[n];


    }
    


};