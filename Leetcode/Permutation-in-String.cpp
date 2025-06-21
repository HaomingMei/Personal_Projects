class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<int> count(26);
        if(s1.size() > s2.size() )
        {
            return false;
        }
        for(int i = 0; i<s1.size(); i++)
        {
            count[s1[i]- 'a'] ++;
            count[s2[i] -'a']--;
        }
        int match=26;
        for(int j = 0 ; j<26; j++){
                if(count[j] == 0)
                {
                    match--;
                }
                else{
                    break;
                }
        }
        if(match == 0)
        {
            return true;
        }

        for ( int i =s1.size(); i<s2.size(); i++){
            count[s2[i]- 'a'] --;
            count[s2[i-s1.size()] -'a']++;
            match = 26;
            for(int j = 0 ; j<26; j++){
                if(count[j] == 0)
                {
                    match--;
                }
                else{
                    break;
                }
            }
            if(match == 0)
            {
                return true;
            }

        }
        return false;
        
    }
};