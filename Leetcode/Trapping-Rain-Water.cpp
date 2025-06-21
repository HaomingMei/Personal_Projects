class Solution {
public:
    int trap(vector<int>& height) {
        // Water does not exist for pole left right most
        // Water at i is the min height of left and right minus current height
        
        // Negative does not count, it means current height is highest,
        // no water will be there

        // Store current sum
        int waterSum = 0;
        // 0 1 2 3 water counts from 1st index to one before the last index
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];
        int leftPtr = 1;
        int rightPtr = height.size() -2;
        // Using two pointers
        // Know min of max left right height - current height = water 
        while(leftPtr <= rightPtr)
        {
            // Move Left to right default
            if(maxLeft <= maxRight)
            {
                // Calculate water height
                
                int currentWater = min(maxLeft, maxRight) - height[leftPtr];
                if(currentWater>0) // Don't want neg.
                {
                    waterSum += currentWater;
                }
                // Update maxLeft
                
                if(height[leftPtr] > maxLeft)
                {
                    maxLeft = height[leftPtr];
                }
                leftPtr++;
                
            }
            else{

                int currentWater = min(maxLeft, maxRight) - height[rightPtr];
                if(currentWater>0) // Don't want neg.
                {
                    waterSum += currentWater;
                }
                // Update maxLeft
                
                if(height[rightPtr] > maxRight)
                {
                    maxRight = height[rightPtr];
                }
                rightPtr--;
            }

            // Decides the next to look at
        }
        return waterSum;
    }
};