class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<vector<int>> res;
        vector<int> comb;

        solve(candidates, res, comb, target, 0, 0);

       
        return res;

    }
    void solve(vector<int> & candidates, std::vector<vector<int>> & res, vector<int>&comb, int target, int sum, int index ){
        int temp = sum;
       // std::cout << "The vector at index " << index << "is: " << std::endl;
       // for(int i = 0; i < comb.size(); i++)
       // {
       //     std::cout << comb[i] << " ";
      //  }
       // std::cout << std::endl;
        if(temp == target){
            //comb.push_back(candidates[index]);

            res.push_back(comb);
            return;
        }
        else if(temp> target || index >= candidates.size()){
            return;
        }
        

        comb.push_back(candidates[index]);
        solve(candidates, res, comb, target, sum +candidates[index], index); // Use the current case/repeat

        // Use the next candidate case
        comb.pop_back();
        //comb.push_back(candidates[index+1]);
        solve(candidates, res, comb, target, sum, index+1);



    }
};