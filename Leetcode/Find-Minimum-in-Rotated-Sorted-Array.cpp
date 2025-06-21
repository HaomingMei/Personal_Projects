class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int left = 0;
        int right = nums.size()-1;

        int currentMin = nums[(left+right)/2];
        // Go to the side with the minmum
        int mid;
        while(left<=right)
        {
           mid = (left + right) / 2;
           if(nums[left] <= nums[right]) // Array is already sorted
           {
               if(nums[left] < currentMin){
                    currentMin = nums[left];
                }
           }
           if(nums[mid] < currentMin){
               currentMin = nums[mid];
           }

           if(nums[mid] >= nums[left]) {
               left = mid+1;
           }
           else if(nums[mid] <= nums[right]){ // Right is smaller go left
               right = mid-1;
           }
           

        }  
        return currentMin;

        
    }
};