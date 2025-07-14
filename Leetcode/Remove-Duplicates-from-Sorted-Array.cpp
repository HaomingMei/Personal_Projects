#include <set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        

        // Ascending Int Array
            // Set data structure  
        int numUnique = 1;
        int prevValue = nums[0];
       // int currentValue;
     //   if (nums.size() > 0){
     //       numUnique = 1;
     //       prevValue = nums[0];
      //  }
     //   else{
        //    return 0;
     //   }
        for(int i = 1; i < nums.size(); i++){
            //currentValue = nums[i];
            if (prevValue != nums[i]){
               // std::cout << currentValue << std::endl;
                nums[numUnique] = nums[i];
                numUnique += 1;
                prevValue = nums[i];
            }
           
        }
        return numUnique;

        // No Duplicates & Return the number of unique elements

        // Return Size of the Data Structure
    }
};