class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Utlize a hashmap, where each num in nums is mapped
        // If mapping already exist, then that is the duplicate
        std::unordered_map<int, int>  mp;
        for(int i = 0; i < nums.size(); i ++){
            auto find = mp.find(nums[i]);
            if(find == mp.end()){
                mp[nums[i]] = 0;
            }
            else{ // If mapped already, then return that nums[i]
                return nums[i];
            }
        }
        return 0;
    }
};