class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         std::vector<vector<int>> res;
         vector<int> subset;
         std::sort(nums.begin(), nums.end()); // Sorting it works because order don't matter
         // It will help with the case in avoiding adding the same value multiple times in the exclude path
         search(nums, subset, res, 0);
         
         return res;
    }
    void search(vector<int>&nums, vector<int>&subset,  std::vector<vector<int>>& res, int index)
    {
        if(index == nums.size()){ // Leaf Node
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        search(nums, subset, res, index+1);

        subset.pop_back(); 
        while( index +1 < nums.size() && nums[index] == nums[index+1])
        {
            // Search this is the exclusion path, where the we decide not to "include"
            // Then if the value is the same again, we don't want it again.
            // That will result in a duplicate
            index+=1;
        }
        search(nums, subset, res, index+1);


    }
};