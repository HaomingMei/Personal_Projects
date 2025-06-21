class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        std::priority_queue<pair<int,int>> pq;
        std::vector<int> resultVector;
        
        for(auto numbers : nums)
        {
            auto search = map.find(numbers);
            if(search != map.end())
            {
                search->second = search->second + 1;
                

            }
            else{
                map.insert({numbers, 1});
            }
            
        }
        // Repeat k times
        for(auto nums: map)
        {   // Number of repetition is the index, value is the number
            pq.push({nums.second, nums.first});
        }
        for(int i = 0; i<k; i++)
        {
            resultVector.push_back(pq.top().second);
            pq.pop();
        }
        return resultVector;
    }
};