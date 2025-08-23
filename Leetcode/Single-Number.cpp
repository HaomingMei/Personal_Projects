class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        // If we xor the same thing, it becomes two
        // meaning an even number of 1s in the same bit will cancel out
        // 4 1 4 -> 4 cancels afterwards, and answer is 1

        // thus we can xor everything
        for(int i =1 ; i < nums.size(); i++){
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};