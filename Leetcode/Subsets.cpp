class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>subset;
        search(nums,0,res, subset);
        return res;
    }

    void search(vector<int>&nums, int index, vector<vector<int>>&res, vector<int>&subset){
        if(index == nums.size()){
            res.push_back(subset); // we are at the bottom children
            return;
        }
        subset.push_back(nums[index]); // Case where we include the current index
        search(nums, index+1, res, subset);

        subset.pop_back(); // Case where we don't include the current index
        search(nums, index+1, res, subset);

    }
};