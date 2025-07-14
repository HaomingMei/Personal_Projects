class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int index; // keep track of the character index that we are looking for
        int totalMov = 0;
        while(s.size() != 0){ // While the string is not empty
            index = s.find(s.back());
            if(index == s.size() - 1){ // No matches found, move to middle
                totalMov += index/2;
            }
            else{ // Found a match, move it to the front of the current string
                totalMov += index;
                s.erase(index, 1);

            }
            s.pop_back();

        }   
        return totalMov;

        // Runtime o(n* (2*m)), where n is the number of character is string s, and m <= n
            // o(n^2)
        // Space Complexity: o(1)
    }
};