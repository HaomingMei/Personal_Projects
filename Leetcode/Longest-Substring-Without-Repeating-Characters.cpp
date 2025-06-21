class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> map;
        int left = 0;
        int maxLength = 0;
        int right = 0;
        cout<< s.size() << endl;
        while(right<s.size())
        {
            
            while(map.find(s[right]) != map.end()){

                map.erase(s[left]);
                left++ ;

            }
           
            map.insert({s[right], right});
            maxLength = std::max(right-left+1, maxLength);
            right++;
        }
        
        return maxLength;
    }
};