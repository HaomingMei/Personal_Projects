class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1) {
            vector<int> myList;
            myList.push_back(nums[0]);
            res.push_back(myList);
            return res;
        }

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> subPerm;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    subPerm.push_back(nums[j]);
                }
            }
            
            vector<vector<int>> perms = permute(subPerm);
            for(vector<int> p : perms) {
                p.push_back(n);  
                res.push_back(p);  
            }
        }
        
        return res;    
    }
};