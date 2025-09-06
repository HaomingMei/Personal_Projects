class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        // We will sort here to  allow us to detect duplicates easily
        std::sort(nums.begin(), nums.end());
        solve(ans, nums, subset, 0);
        return ans;


    }
    void solve(vector<vector<int>> & ans, vector<int> & nums, vector<int> & subset, int index){
        // Base case, when the index is out of bound

        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        

        // Choice 1: Include the current value
        subset.push_back(nums[index]);
        solve(ans, nums, subset, index+1);

        // We will have to skip the duplicates by checking the current index value at nums is equal to the index + 1 value at nums


        // Choice 2: Skip the current value
        subset.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index+=1;
        }
        solve(ans, nums, subset, index+1);

    }
};