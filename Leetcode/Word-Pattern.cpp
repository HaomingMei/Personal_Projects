#include <iostream>
#include <unordered_map>
#include <string>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Implementation: Dual hashmap that crosschecks to ensure
        // bijection mappings
        //std::cout << pattern[0] << endl;
        //std::cout << s[0] << endl;

        // Setup pointer to characters of pattern
        char * current_char = &pattern[0];
       // std::cout << *current_char << endl;
        //current_char++;
        //std::cout << *current_char << endl;

        char* i = &s[0];
        // This outputs the address
            //std::cout << static_cast<void*>(&s[0]) << endl;
        char* j = i;
        // Case where either of the string is NULL
     
        // Create the hashmaps
        std::unordered_map<char, std::string> char_to_word_map;
        std::unordered_map<std::string, char> word_to_char_map;
        char * char_to_word_end = i + s.size(); // Include the NULL terminator
        char * last_char = current_char + pattern.size();
        std::cout << "Size of string s is " << s.size() << endl;
        // Iterating through the s string
        std::cout << "The ending address of the char_to_word_end is " << static_cast<void *>(char_to_word_end) << "\n" << endl;
        while(j != char_to_word_end+1 && current_char != last_char ){

            // Case 1: j is at "_", meaning we found a word
            std::cout << "The value of j is " << *j << endl;
            std::cout << "The address of j is " << static_cast<void *>(j) << "\n" << endl;

            if(*(j+1) == ' ' || j+1 == char_to_word_end){
                // Have a word
                
                string temp(i, j-i+1); // Compies the string without the null terminator
            
                std::cout << temp << endl;
                // Check hashmap1
                auto hash1 = char_to_word_map.find(*current_char);
                if(hash1 != char_to_word_map.end()){ // If found
                    if(char_to_word_map[*current_char] != temp){
                        return false;
                    }
                }
                else{
                    char_to_word_map[*current_char] = temp;
                   
                }
                // If exist?
                auto hash2 = word_to_char_map.find(temp);
                if(hash2!= word_to_char_map.end()){ // Exists!
                    if(word_to_char_map[temp] != *current_char){
                        return false;
                    }
                }
                else{ // Does not exist
                    word_to_char_map[temp] = *current_char;
                }
                j +=2;
                i = j;
                current_char++;

            }
            // Case 2: j is not at "_", keep incrementing
            else{
                j++; // Move on to the next character in the string
            }
        }
        if(current_char != last_char ||  j != char_to_word_end+1){ // Considers the case where there is more characters or words than the other
            return false;
        }
        return true;
    }
};