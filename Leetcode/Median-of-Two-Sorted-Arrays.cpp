class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(); // A
        int size2 = nums2.size();  // B
        if(size2>size1){
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0;
        int right = nums2.size();

        int totalSize = size1+size2;
        int halfSize = std::floor((totalSize)/2);
        int partA;
        int partB;
        double answer = 0.0;
        while(left<=right)
        {
            partB = left + (right-left) /2;
            partA = floor(totalSize/2) - partB;
            
            
            // Left and Right Partition of A & B
            int left1 = (partA>0) ? nums1[partA-1]: INT_MIN;
            int right1 = (partA<size1) ? nums1[partA] : INT_MAX;
            int left2 = (partB>0) ? nums2[partB-1]: INT_MIN;
            int right2 = (partB<size2) ? nums2[partB] : INT_MAX ;
            
            // Cross comparison with left partition and right partition
            if(left1<= right2 && left2 <= right1)
            {
                // Found correct partition
                if(totalSize %2 == 0){
                    answer = (std::max(left2, left1) + std::min(right1, right2) ) / 2.0;               
                }
                else{
                    answer = std::min(right1,right2); 
                   
                }
                return answer;
            }
            else if(right1<left2){
                right = partB -1;
            }
            else{
                // Search right
                left = partB +1;
            }
        }
       
        return answer;
    }
};