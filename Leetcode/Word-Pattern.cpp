#include <string>
#include <unordered_map>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> hashmap1; // Character to Word
        std::unordered_map<std::string, char> hashmap2; // Word to Character

        int i = 0; // Iterator for characters (pattern)
        int j = 0; // Iterator for words (s)
        int strBeginIndex = 0;
        while(i< pattern.size() && j<  s.size()){
            
            if(s[j] == ' ' || j == s.size() - 1){ // If we are at the end or found a space, that's a word
                std::string tempStr(s, strBeginIndex, j - strBeginIndex );
                if(j == s.size() - 1){ // Get the last character in string s
                    tempStr += s[j];
                }
                //std::cout << tempStr << std::endl;


                // Checking the hashmap here:

                auto find1 = hashmap1.find(pattern[i]);

                if(find1 != hashmap1.end()){ // Charcter is already mapped
                    if(find1->second != tempStr ){
                        return false;
                    }
                } 
                else{ // Character has not been mapped before
                    hashmap1[pattern[i]] = tempStr; // Mapping the character to the word
                }

                // Check if the word is already mapped
                auto find2 = hashmap2.find(tempStr);
                if(find2 != hashmap2.end()){ // Word is already mapped              
                    //std::cout << "test 2" << std::endl;
                    // Check if the current character is equal to what is mapped
                    if(find2 -> second != pattern[i]){
                        return false;
                    }
                }
                else{ // If the word have not been mapped
                    hashmap2[tempStr] = pattern[i];
                }
                strBeginIndex = j + 1;
                i+=1;
            }
            j+=1;
        }

        // Conditon here to Make sure both reached the end
        if(i != pattern.size() || j != s.size()){
            return false;
        }
        return true;
    }
};