class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()){
            return {};
        }
        unordered_map<string, vector<string>> map;
        for(string s:strs)
        {

            string key = s;
            std::sort(key.begin(), key.end());

            map[key].push_back(s);

        }
        vector<vector<string>> ans;
        for(auto &item: map){
            ans.push_back(item.second);
        }
    
        return ans;
    }
};