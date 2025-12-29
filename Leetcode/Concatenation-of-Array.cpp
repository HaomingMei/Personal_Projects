#include <vector>
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> ans(2*numSize);
        for(int i = 0; i < numSize; i++){
            ans[i] = nums[i];
            ans[i+numSize] = ans[i];
        }
        return ans;
    }
};