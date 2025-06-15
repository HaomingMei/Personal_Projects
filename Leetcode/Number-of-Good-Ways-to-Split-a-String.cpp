class Solution {
public:
    int numSplits(string s) {
      //std::unordered_map<char, int> Left_Freq;
      std::unordered_map<char, int> Right_Freq;
      int Left = 0;
      int LeftUnique = 0;
      int goodSplit = 0;
      bool prev = false;
      for(int i = 0; i< (s.end()-s.begin()); i ++ ){
        Right_Freq[s[i]] += 1;
    
      }

      for(int j = 0; j <= ((s.end()-s.begin())-2); j++){
        
        if(Right_Freq[s[j]]-1 == 0){ // If There is only 1 left, then erase it
            Right_Freq.erase(s[j]);
        }
        else{ // Else, there will be 1 or more left after removing, decrease frequency by 1
            Right_Freq[s[j]] -= 1; 
        }
      //  auto LeftSearch = Left_Freq.find(s[j]);
        //if( LeftSearch == Left_Freq.end() ){ // Doesn't exist
        //    Left_Freq[s[j]] +=1;
       // }
        if( (Left & (1<<s[j]-97)) == 0){
            LeftUnique += 1;
            Left |= (1<<s[j]-97);
        }
       // if(Right_Freq.size() == Left_Freq.size() ){
        if(Right_Freq.size() == LeftUnique){
            goodSplit +=1;
            if(prev == false){
                prev = true;
            }
        }
        else{
            if(prev == true){
                return goodSplit;
            }
        }
      }
      return goodSplit;
    }
};