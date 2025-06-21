class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()<2){
            return 1;
        }
        if(k>= s.size())
        {
            return s.size();
        }
        int right= 0;
        int left = 0;
        std::vector<int> count(26);

        int currMax = 0;
        
        int result= 0;
        int size = s.size();

        while(right< size )
        {
            count[s[right] - 'A']++;
            currMax = std::max(currMax, count[s[right] - 'A'] );
            // When its invalid or maxFreq does surpass the ones from before
            if(right-left +1-currMax > k)
            {
                count[s[left]-'A']--;
                left++;
            }
            // Update max on valid
            result = std::max(result, right-left +1);
            right++;
        }   
        return result;
    }
};