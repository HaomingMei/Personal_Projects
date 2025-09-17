class Solution {
public:
     struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int x : v) {
                // combine hashes
                seed ^= hasher(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<std::string>> ans;
        std::unordered_map<vector<int>, vector<std::string>, VectorHash> map;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            vector<int>freq(26,0); // Calculate its freq for each cahr
            for(int j = 0; j <temp.size(); j++){
                freq[temp[j]-'a'] +=1;
            }
          //  auto p = map.find(freq);
            //if(p != map.end()){ // If found, append to vector of strings
                map[freq].push_back(temp);
            //}
            //else{
              //  map[freq] = {temp}; // Else create a new vector and append it
            //}
        }
        for(auto &item: map){
            ans.push_back(item.second);
        }
        return ans;
    }
};