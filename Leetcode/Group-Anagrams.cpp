1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        if(strs.empty()){
5            return {};
6        }
7        unordered_map<string, vector<string>> map;
8        for(string s:strs)
9        {
10
11            string key = s;
12            std::sort(key.begin(), key.end());
13
14            map[key].push_back(s);
15
16        }
17        vector<vector<string>> ans;
18        for(auto &item: map){
19            ans.push_back(item.second);
20        }
21    
22        return ans;
23    }
24};