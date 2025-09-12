class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Revisit 3 (Practice)
        vector<int> comb;
        vector<vector<int>> ans;
        solve(ans, comb, candidates, target, 0);
        return ans;
        
    }

    void solve(vector<vector<int>>& ans, vector<int>& comb, vector<int> & candidates, int target, int index){
        if(target == 0){ // Combination Sum reached the target
            ans.push_back(comb);
            return;
        }
        else if(target < 0){ // Overshoot, return
            return;
        }

        if (index == candidates.size()){
            return;
        }

        comb.push_back(candidates[index]); // Choice 1: Include the current
        solve(ans, comb, candidates, target-candidates[index], index);

        comb.pop_back(); // Choice 2: Skip the current
        solve(ans, comb, candidates, target, index + 1);

    }
};