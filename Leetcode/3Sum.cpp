class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> resultVector;
        if(nums.size()<3)
        {
            return resultVector;
        }
        std::sort(nums.begin(), nums.end());
        // Loop through the rwhole nums
        for(int current = 0; current < nums.size()-2 ; current++)
        {
            if(nums[current] >0)
            {
                return resultVector;
            }
            int left = current + 1; // points to one right of current
            int right = nums.size()-1; // points to the last element

            while(left<right) 
            // We don't want to the two pointers to cross, will cause duplicate
            {   
                if(current>0 && nums[current] == nums[current-1])
                {
                    break;
                }
                int target =  (0 - nums[current]);
                // Find target
                // These won't go if left and right value equal to target
                while(nums[left] + nums[right] >target && left<right) // Too Large, move right pointer left 
                {
                    right--; // move to a position where sum is equal or less to target
                }
                // if Too Small move left pointer right
                // Until its equal or greater than the target
                while(nums[left] + nums[right] < target && left<right)
                {
                    left++;
                }
                // Push_back the last duplicated on each side
                
                if(left != right && target == nums[left] + nums[right])
                {
                    resultVector.push_back({nums[current], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left] == nums[left-1])
                    {
                            left++;
                    }
                    while(left<right && nums[right] == nums[right+1])
                    {
                            right--;
                    }
                }
                
                

                

            }
        }
        return resultVector;
    }
};