#include <limits>
#include <unordered_map>
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int globalMin = -1;
        int numsSize = nums.size();
        if(numsSize <3){
            return -1;
        }
        // abs(b-a) + abs(c-b) + abs(c-a)
        // b-a+c-b+c-a = 2c-2a = 2(c-a) -> largest indices and the smallest indices value
        std::unordered_map<int, std::vector<int>> mp;
        // Value : Vector of the indices with the same value
        for(int i = 0; i< numsSize; i++){ // o(n)
            mp[nums[i]].push_back(i); 
        }
        
        for(const auto& it: mp){
            if(it.second.size() >= 3){ // There has to be more than 3 indices else we cannot construct a 3 element tuple              
                std::vector<int> tempVector(it.second.begin(), it.second.end());
                // Iterate through the whole vector
                //std::cout << tempVector[2] << std::endl;
                //std::cout << tempVector[0] << std::endl;
                int tempVectorSize = tempVector.size();
                int minSum  = 2*(tempVector[2]-tempVector[0] );
                for(int i = 1; i < tempVectorSize-2; i++)
                {
                    int sum = 2*(tempVector[i+2]-tempVector[i]);
                    if(minSum > sum ){
                        minSum = sum;
                    }

                }
 
                if(minSum < globalMin  || globalMin == -1){
                    globalMin = minSum;
                }
                
            }
        }
        return globalMin; // globalMin will stay -1 if no vector exceed 3


    }
};