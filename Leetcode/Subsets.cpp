class Solution {
public:

    // Revisiting this Problem: 2nd Try
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(ans, nums, subset, 0 );
        return ans;

    }
    void solve(vector<vector<int>> & ans, vector<int>&nums, vector<int>&subset, int index){
        // Base Case
        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }

        // Choice: Include the Current
        subset.push_back(nums[index]);
        solve(ans, nums, subset, index+1);
        // Choice: Skip the Current
        subset.pop_back();
        // Backtrack will pop everything necessary before the exclusion route
        solve(ans,nums,subset, index+1);
    }
};