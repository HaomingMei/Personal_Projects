#include <iostream>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet;
        for(auto n : nums)
        {
            if(mySet.find(n) != mySet.end())
            {
                return true;
            }
            else{
                mySet.emplace(n);
                
            }
        }
        return false;

        
    }
};