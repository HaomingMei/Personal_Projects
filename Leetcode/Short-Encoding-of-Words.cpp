#include <algorithm>
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int len = 0;// Keeps track of the current length of the reference string s
        int lastSize;
        while(words.size()!=0){ // While the vector is not empty
            lastSize = words[words.size()-1].size();
            len += lastSize+1;
            for ( int j = 0; j < words.size()-1; j++){
                int count = 0; // Count the number of matched characters so far
                int lastIdx1 = lastSize-1;  
                int lastIdx2 = words[j].size()-1; // lastIndex we are comparing to
                std::string currentWord = words.back();
                if(currentWord == words[j]){
                    words.erase(words.begin() + j); // Erase the exact same one
                    j -= 1; // Do the ++ and we have the check the same index
                    continue;
                }
                while(lastIdx1 >= 0 && lastIdx2 >=0 && currentWord[lastIdx1]==words[j][lastIdx2] ){
                    count += 1;
                    lastIdx1 -=1;
                    lastIdx2 -=1;
                }
                if( count > 0){ // There are matches, so we merge?
                    if(count == lastSize){ // We overwrite the back with a longer word
                        len+= words[j].size() - lastSize ; // add the difference
                        std::string tempWord = words[j];
                        words.erase(words.begin() + j); // Erase the larger word
                        words[words.size()-1] = tempWord; // Overwrite it
                        j = -1;
                        lastSize = words.back().size();
                        continue;
                    }
                    else if (count == words[j].size()){ // Jth word is merged to the back word
                        words.erase(words.begin() + j); // Erase the jth word
                        j -=1;  // Check the same index again in the next iteration
                        continue;
                    }
                }
            }
            words.pop_back(); // Checked all the words, pop the back

        }
        return len;
    }
};