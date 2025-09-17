class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int left, right, mid;
        int val;
        vector<std::pair<int, int>> temp; // Keeps track of the value and the index
        for(int i = 0; i < nums.size(); i++){
            temp.push_back({nums[i],i});
        }
        std::sort(temp.begin(), temp.end());

        for(int i = 0 ; i + 1 < temp.size(); i ++ ){
            left = i + 1;
            right = temp.size() - 1;
            mid = (left+right)/2;
            val = temp[i].first;
            ans.push_back(temp[i].second);
            while(left<= right && left < temp.size() && right < temp.size()){
                int sum = val + temp[mid].first;
                if(sum == target){
                    ans.push_back(temp[mid].second);
                    return ans;
                }
                else if(sum < target){
                    left = mid + 1;

                }
                else{
                    right = mid - 1;
                }
                mid = (left+right)/2;

            }
            ans.pop_back();

        }
        return ans;
    }
};