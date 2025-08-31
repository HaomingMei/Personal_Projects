class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<std::string>> ans;
        vector<std::string> part;
        //std::string temp(1, s[0]);
        //part.push_back(temp);
        solve(ans, s, part, 0);
        return ans; 
    }
    void solve(vector<vector<std::string>>& ans, string s, vector<std::string>& part, int index){
        // Base cases:
        // Check palidrome
       // if(!part.empty() && checkPalindrome(part.back()) == false){
         //   return;
        //}
        if(index == s.size()){
            ans.push_back(part);
            return;
        }

        // Decisions : Append to the current index in part, or append as a new string
      //  std::cout << "Pass 1 " << std::endl;
        // Start a new one
       // part.push_back(string(1, s[index]));

        //if (checkPalindrome(part.back())) {
          //  solve(ans, s, part, index+1);
        //}
        //part.pop_back();

        //if(!part.empty()){
          //  string old = part.back();
           // part.back() += string(1,s[index]);
            //if (checkPalindrome(part.back())) {
              //  solve(ans, s, part, index+1);
            //}
            //part.back() = old;
        //}



        // Use the existing one
         for (int i = index; i < s.size(); i++) {
            string sub = s.substr(index, i - index + 1);
            if (checkPalindrome(sub)) {
                part.push_back(sub);
                solve(ans, s, part, i+1);
                part.pop_back();
            }
        }

    }

    bool checkPalindrome(string s){
        int length = s.size();
        int left = 0;
        int right = length -1;
       //std::cout << "Hi " << std::endl;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left+= 1;
            right -=1;
           // std::cout << "Pass 3 " << std::endl;
        }
        //std::cout << "Pass 4 " << std::endl;
        return true;
    }
};