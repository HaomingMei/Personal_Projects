class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num;
        // First value is the number, second is the index
        std::vector<int> resultVector;
        for(int i =0; i<nums.size(); i++)
        {
            resultVector.push_back(i);
            auto search = num.find(target-nums[i]);
            if(search != num.end())
            {
                resultVector.push_back(search->second);
                return resultVector;

            }
            else{
                resultVector.pop_back();
                num.insert({nums[i],i}); 
                // Insert value and index pair
            }
            
        }

        return resultVector;
    }
};