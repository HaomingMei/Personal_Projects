class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0, 1, 2, 3, 4 ODD case, the middle is always the max or nums.size() divided by 2 since it's the center piece

        //  EVEN CASE:
        // 0,1,2,3 
        // (3*4) /2 Perfect pairs

        // Use the expected sum - actual sum = missing num

        int actual_sum = 0;
        for(int i = 0; i<nums.size(); i++){
            actual_sum += nums[i] ;
        }
        return (((nums.size())*(nums.size()+1))/2) - actual_sum;




    }
};