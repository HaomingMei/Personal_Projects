class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Leetcode Review: 2 (need to learn DP)
        vector<std::string> part;
        vector<vector<std::string>> ans;
        solve(part, ans, s, 0);
        //std::cout << s.size() << std::endl;
        return ans;
    }
    void solve( vector<std::string>&part, vector<vector<std::string>>&ans, string s, int index){
        if(index >= s.size()){
            ans.push_back(part);
            return;
        }


        for (int i = index; i < s.size(); i++){
            string temp = s.substr(index, i - index + 1);
            if(checkPalidrome(temp) == true){
                part.push_back(temp);
                solve(part, ans, s, i+1); // Right most character of string + 1 for the next char
                part.pop_back();
            }
        }
    }
    bool checkPalidrome(string temp){
        int left = 0;
        int right = temp.size()- 1;
        while(left<= right){
            if(left == right){
                return true;
            }
            if(temp[left] != temp[right]){
                return false;
            }
            left += 1;
            right -=1;

        }
        return true;
    }
};