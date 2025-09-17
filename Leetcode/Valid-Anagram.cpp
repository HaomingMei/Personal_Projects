class Solution {
public:
    bool isAnagram(string s, string t) {
        // Length is the same
        if(s.size() != t.size()){
            return false;
        }
        // Freq of the words are the same (o(n)) insert to unordered map for both
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for(int i = 0; i < s.size(); i++){
            s_map[s[i]] += 1;
            t_map[t[i]] += 1;
        }

        for(auto item: s_map){
            if(item.second != t_map[item.first]){ // if freq different, return false
                return false;
            }
        }
        return true;

    }
};