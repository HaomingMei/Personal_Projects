class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        unordered_map<string, vector<string>> map;
        for(const auto& s:strs)
        {

            vector<int>freq(26,0); // Calculate its freq for each cahr
            for(char ch: s){
                freq[ch-'a'] +=1;
            }
            string key= to_string(freq[0]); // Custom hashing for string
            for(int i=1;i<26;i++){
                key+=','+to_string(freq[i]);
            }
            map[key].push_back(s);

        }
            vector<vector<string>> ans;
        for(auto &item: map){
            ans.push_back(item.second);
        }
        return ans;
    }
};