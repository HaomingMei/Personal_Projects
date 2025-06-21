class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> str;
        recurseParenthesis(n, str, 0, 0, "");
        return str;
    }
    void recurseParenthesis(int n, std::vector<string> &str, int left, int right, string s){
        if(left == right && left == n)
        {
            str.push_back(s);
            return;
        }
        if(left +1 <= n && left>= right){
            recurseParenthesis(n, str, left+1, right, s+'(');
        }
        if(left> right){
             recurseParenthesis(n, str, left, right+1, s+')');
        }
           
    }
};