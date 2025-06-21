class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string word: strs) // eat tea -> aet: eat, tea
        {
            string temp = word;
            std::sort(word.begin(), word.end());
            map[word].push_back(temp);
        }
        std::vector<vector<string>> resultVector;
        for(auto group: map)// aet: eat, tea
        {
            resultVector.push_back(group.second);
        }
        return resultVector;
    }
};