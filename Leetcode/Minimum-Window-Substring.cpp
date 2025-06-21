
class Solution {
public:
    bool checksubString(std::vector<int> &c)
    {
        int sizeC = c.size();
        for(int i =0; i< sizeC; i++)
        {
            if(c[i] >0)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        
        std::vector<int> count(52);
        if(sizeT> sizeS){
            return "";
        }
        for(int i = 0; i<t.size(); i++)
        {
            // Check upper
            if(s[i]>= 'a' && s[i] <= 'z')
            {
                count[s[i] - 'a' + 26]--;
                
            }
            // check lower
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                count[s[i] - 'A'] --;
                
            }   
            if(t[i]>= 'a' && t[i] <= 'z')
            {
                count[t[i] - 'a' + 26]++;
                
            }
            // check lower
            else if(t[i] >= 'A' && t[i] <= 'Z')
            {
                count[t[i] - 'A'] ++;
                
            }  
  
            
        }
        int minStringStart = -1;
        int minStringEnd =-1;
        // Check if all <=0
        int minLen = INT_MAX;
        int foundFlag;
        int left =0;
        int right = t.size()-1;
        while(left<=right && right<s.size())
        {
            
            while(checksubString(count) == true && left<=right )
            {   
                
                if(minLen> right-left+1)
                {
                    minStringStart = left;
                    minStringEnd = right;
                    minLen = right-left+1;
                }
                
                if(s[left]>= 'a' && s[left] <= 'z')
                {
                    count[s[left] - 'a' + 26]++;
                    
                }
                // check lower
                else if(s[left] >= 'A' && s[left] <= 'Z')
                {
                    count[s[left] - 'A'] ++;
                    
                }
                
                left++;
            

            }
                  // Left ++
                // ++ on left check upper or lower
            // Check if <= for all element, until we find don't move left pointer
            if(right==sizeS-1)
            {
                left++;
            }
            else{
                right++;
              if(s[right]>= 'a' && s[right] <= 'z')
                {
                    count[s[right] - 'a' + 26]--;
                    
                }
                // check lower
                else if(s[right] >= 'A' && s[right] <= 'Z')
                {
                    count[s[right] - 'A'] --;
                    
                }
            }         
        }
        string answer = "";
        if(minStringStart == -1 && minStringEnd == -1)
        {
            return answer;
        }
        else{
            for(int i = minStringStart; i<=minStringEnd; i++)
            {
                answer = answer + s[i];
            }
        }
        
        return answer;
        // For Loop the index start to end variable to get string
    }
};