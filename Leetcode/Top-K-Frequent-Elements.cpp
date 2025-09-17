class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map; // Represents the value and its rep
        int numSize = nums.size();
        for(int i = 0; i <numSize; i++){
            map[nums[i]] ++;
        }
        vector<pair<int,int>> items(map.begin(), map.end()); // Copy from hashmap to vector

        std::sort(items.begin(), items.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second;
        });
        for(int j = 0; j<k; j++){ // insert k times
            ans.push_back(items[j].first);
        }
        return ans;
    }
};