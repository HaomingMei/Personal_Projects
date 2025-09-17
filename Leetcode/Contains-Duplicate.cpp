class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Need to keep track of the freq  of the num
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size(); i++){
            if(map[nums[i]] >=1){
                return true;
            }
            map[nums[i]] ++;
        }
        return false;
    }
};