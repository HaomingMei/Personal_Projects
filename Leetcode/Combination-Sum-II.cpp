class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        std::sort(candidates.begin(), candidates.end());
        solve(ans, comb, candidates, target, 0);
        return ans;
    }

    void solve(vector<vector<int>> & ans, vector<int> &comb, vector<int>& candidates, int target, int index){
        if(target==0 ){ 
            ans.push_back(comb);
            return;
        }
        else if(target < 0 ){
            return;
        }
        if(index == candidates.size()){
            return;
        }

        // Choice 1: Include the current
        comb.push_back(candidates[index]);
        solve(ans, comb, candidates, target-candidates[index], index+1);

        comb.pop_back(); // Choice 2: Skip the duplicates since the other path considered it already
        
        while(index+1 < candidates.size() && candidates[index] == candidates[index+1]){
            index += 1;
        }
        solve(ans, comb, candidates, target, index+1);

    }
};