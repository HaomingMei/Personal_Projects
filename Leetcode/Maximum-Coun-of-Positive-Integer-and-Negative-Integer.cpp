class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int numNeg =bSearch(nums, 0);
        int numPos =  nums.size() - bSearch(nums,1);
        return std::max(numNeg, numPos);
    }
private:
    int bSearch(vector<int> &nums, int target){
        // We want to get the first index from left to right that fulfills >= target
        // Negative: 0
        // Positive: 1
        // Number of elements since the index is 1 to the right of where all the indices of what what we wanted

        int l = 0 ;
        int r = nums.size() - 1;
        int result = nums.size();
        while(l<=r){
            int m = (l+r) /2;
            if(nums[m] < target){
                l = m + 1; // go right
            }
            else{ // >= 0
                r = m - 1; // go left
                result = m;
            }

        }
        return result;
    }
};