class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right =nums.size()-1;
        
        int mid = left + (right-left)/2;
        int min = nums[mid];
        int pivot = mid;
        while(left<= right){
            mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < min)
            {
                pivot = mid;
                min = nums[mid];
            }
            if(nums[left] <= nums[right] )
            {
                // Completely sorted pivot is at the left
                if(nums[left] < min)
                {
                    pivot = left;
                    
                }
                break;
            }
            if(nums[mid] <= nums[right])
            {
                // serach left
                right = mid -1;
            }
            else if(nums[mid] >=nums[left])
            {
                left = mid +1;
            }
        }
        // Gotten the pivot
        int searchLeft;
        int searchRight;
        if(pivot ==0)
        {
            // At origin, perform norma binary search
            searchLeft = 0;
            searchRight = nums.size()-1;
        }
        else if(nums[pivot] <= target && nums[nums.size()-1]>=target){
            searchLeft = pivot;
            searchRight = nums.size()-1;
        }
        else{
            searchLeft = 0;
            searchRight = pivot-1;
        }
        int middle ;
        while(searchLeft<= searchRight)
        {
            // Perform binary search
            middle = searchLeft + (searchRight-searchLeft)/2;

            if(nums[middle] == target)
            {
                return middle;
            }
            else if(nums[middle] > target)
            {
                // search left

                searchRight = middle-1;
            }
            else if(nums[middle] < target)
            {
                searchLeft = middle+1;
            }
        }
        return -1;


        
    }
};