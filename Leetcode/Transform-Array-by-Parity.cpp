#include <cmath>
#include <algorithm>
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int numsSize = nums.size(); // o(n) space 
        for(int i = 0; i < numsSize; i ++){ // o(n) run time
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        } 
        // Number of Even == Odd, or Even > Odd by 1
        // Thus, the non-decreasing array will have numsSize / 2 of even and odd if it's even size
        // ceil(numsSize/2)EVEN and ceil(numsSize/2)-1 ODD if odd size

       // std::vector<int> ans(nums.begin(), nums.end());
        std::sort(nums.begin(), nums.end()); // o(n*log(n));
        return nums;
    
        // Total Space Complexity: o(n), n = number of elements in nums
        // Total Time Complexity: o(n*log(n)), n = number of elements in nums
    }
};