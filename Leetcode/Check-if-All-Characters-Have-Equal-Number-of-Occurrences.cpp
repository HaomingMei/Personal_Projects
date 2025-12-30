class Solution {
public:
    bool areOccurrencesEqual(string s) {
        std::unordered_map<char, int> mp;
        for(char c: s){
            mp[c] += 1;
        }
        int numOcc = mp.begin()->second;
       // std::cout << numOcc << std::endl;
        //std::cout<< mp.begin()->first <<  std::endl;
        for(const auto& it: mp){
            if(it.second != numOcc){
                return false;
            }
        }
        return true;
    }
};