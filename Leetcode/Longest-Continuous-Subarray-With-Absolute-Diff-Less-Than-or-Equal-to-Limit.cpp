#include <cmath>
#include <dequeue>
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        dequeue<int> dq_increase;
        dequeue<int> dq_
        pq.push_back(nums[0]);
        int longestWindow = 1;
        int currWinSize = 1;
        if(nums.size() == 1){
            return 1;
        }
        int i = 0; 
        int j = 1; // Sliding Window Across nums
        int currentMax = nums[0];
        int currentMin = nums[0];
      //  int l = 0;
        int r = 0; // Pointers to check against the limit for the new value to be added to the sliding window
        while ( j < nums.size() ){
            int accepted = 1;
           // for(int r = i; r < j; r++){
            //    if(abs(nums[j]-nums[r] ) > limit){
            //       accepted = 0;
            //       break;
            //    }
           // }
            pq.push_back(nums[j]);
            if(pq.top() - ) > limit){
                accepted = 0;
            }
            if(accepted == 0){ // One of the elements exceeded
                i += 1;
                j = i +1;
                if(currWinSize > longestWindow){
                    longestWindow = currWinSize;
                }
                currWinSize = 1;
                
            }
            else{ // Non Exceeded
                currWinSize += 1;
                if(j == nums.size() - 1){

                    if(currWinSize > longestWindow){
                        longestWindow = currWinSize;
                    }
                }
                j += 1; // Increment the window right bound
            }


        }
        return longestWindow;
    }
};