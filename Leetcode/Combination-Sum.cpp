class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(ans, comb, candidates, target, 0);
        return ans;


        
    }
    void solve(vector<vector<int>> & ans, vector<int> & comb, vector<int> & candidates, int target, int index){
        // Base Case 1: Exceeded target
        if(target < 0){
            return;
        }
        else if(target == 0){
            ans.push_back(comb);
            return;
        }
        // Base Case 2: No one elements to choose from
        if(index >= candidates.size()){
            return;
        }

        // Choice 1: Reusing the same one
        comb.push_back(candidates[index]);
        solve(ans, comb, candidates, target-candidates[index], index); 

        // Choice 2: Skipping the current
        //if(index + 1 >= candidates.size()){ // can't do that cause we need index == candidates sometimes to push comb to ans
          //  return;
        //}
        comb.pop_back();
        solve(ans, comb, candidates, target, index+1);

    }
};