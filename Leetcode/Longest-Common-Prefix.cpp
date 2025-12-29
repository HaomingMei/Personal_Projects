1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        std::string currentPrefix;
5        int prefixSize = 1;
6        int strSize = strs.size();
7        if(strs.size() == 0){
8            return "";
9        }
10        else if(strs[0].size() == 0){
11            return "";
12        }
13       // else{
14        //    currentPrefix = strs[0].substr(strs[0].begin(),strs[0].begin()+1);
15
16       // }
17       
18        while(prefixSize<=strs[0].size()){
19            currentPrefix.push_back(strs[0][prefixSize-1]);
20            for(int i = 0; i <strSize; i++){
21                // Match
22                string currentStr = strs[i];
23                if(prefixSize > currentStr.size()){ // Ensure that the string is at least as long as the prefix
24                    currentPrefix.pop_back();
25                    return currentPrefix;
26                }
27                else{
28                    int currentStringSize = currentStr.size();
29                   
30                    for(int k = 0; k< prefixSize; k++){
31                        if(currentPrefix[k] != currentStr[k] )
32                        {
33                            currentPrefix.pop_back();
34                            return currentPrefix;
35                        }
36                    }
37      
38
39                }
40                // Mismatch case
41            }
42            prefixSize+=1;  
43 
44        }
45        return currentPrefix;
46
47    }
48};