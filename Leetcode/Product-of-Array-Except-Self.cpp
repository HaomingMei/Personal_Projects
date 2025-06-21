class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> resultVector;
        resultVector.resize(nums.size(), 1);
        vector<int> preFix;
        preFix.resize(nums.size()+1, 1);
        vector<int> postFix;
        postFix.resize(nums.size()+1, 1);
        
        for(int i = 0; i<nums.size(); i++)
        {
            preFix[i+1] = preFix[i] * nums[i];     
            postFix[postFix.size()-2-i] = postFix[postFix.size()-1-i] * nums[nums.size()-1-i];       
        }
        for(int i=0; i<nums.size(); i++)
        {
            resultVector[i] = preFix[i] * postFix[i+1];
        }
        return resultVector;
    }
};