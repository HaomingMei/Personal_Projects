class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<std::pair<int,int>> map; // Keeps track of the number and its index
        for(int i = 0; i <nums.size(); i ++){
           map.push_back({nums[i],i});
        }
        std::sort(map.begin(),map.end());

        int l = 0;
        int r = map.size()-1;
 
        while(l<r && l < map.size()&& r < map.size()){
            int sum = map[l].first + map[r].first;
            if(sum== target){
                ans.push_back(map[l].second);
                ans.push_back(map[r].second);
                return ans;
            }
            else if(sum< target){
                l+=1;
            }
            else{
                r-=1;
            }

        }
        
        return ans;
    }
};