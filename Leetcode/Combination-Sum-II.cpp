class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<vector<int>> res;
        std::sort(candidates.begin(), candidates.end()); // can do this since the order o the vector in the res does not matter
        vector<int> comb;
        solve(candidates, res, comb, target, 0, 0 );
        //vector<vector<int>> final_res;
        //while(!res.empty()){
          //  final_res.push_back(*res.begin());
            //res.erase(res.begin());
       // }
        return res;
    }
    void solve(vector<int>& candidates, std::vector<vector<int>> &res, vector<int>&comb, int target, int sum, int index){
        // Base cases
        if(sum == target){
           // vector<int> temp(comb.begin(), comb.end());
            
           // std::sort(temp.begin(), temp.end());
            res.push_back(comb);
            return;
        }
        else if(sum > target || index >= candidates.size()){
            return;
        }
        comb.push_back(candidates[index]);
        // Case where we use the current
        solve(candidates, res, comb, target, sum + candidates[index], index+1);
        
        comb.pop_back(); // Case where we do not use the current candidate
        // If we are skipping the current, and the next canadiate is the same, then we skip those as well
        int temp = candidates[index];
        int next = index+1;
        while(next < candidates.size() && temp == candidates[next]){
            next+=1;
        }
        solve(candidates, res, comb, target, sum, next);
    }
};
