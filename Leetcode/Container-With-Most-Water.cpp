class Solution {
public:
    int maxArea(vector<int>& height) {
        // find 2 poles, the max height of water is the pole with the lesser height

        // Method to find area of selected poles
        // For loop

        // Lest pole height * width (index difference)
        // width is larger pole index - smaller pole index 
        // Store all the area
        std::vector<int> test;
        test.push_back(0);
        // Use a right pointer, usually largest is most left and most right pole
        int right = height.size()-1;
        int left = 0; 
        while(left<right)
        {
            int width = right-left;
            int h = min(height[right], height[left] );

            if(width*h > test.front())
            {
                test.pop_back();
                test.push_back(width*h);
            }
            if(height[left]<=height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        

        return test.front();
    }
};