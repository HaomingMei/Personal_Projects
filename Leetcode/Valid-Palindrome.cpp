class Solution {
public:
    bool isPalindrome(string s) {
        
        
        // Filters out non ASCII
        const char* begin = s.c_str();
        const char* end = begin + s.size()-1;

        while(begin<end)
        {
            // left side move to a number or letter
            while(!isalnum(*(begin)) && begin<end)
            {
                begin++;
            }
            while(!isalnum(*(end)) && begin<end)
            {
                end--;
            }
            if(begin>=end)
            {
                break;

            }
            if(tolower(*(begin)) != tolower(*(end)))
            {
                return false;
            } 

            begin++;
            end--;
            
        }
    
    
        return true;




        
    }
};