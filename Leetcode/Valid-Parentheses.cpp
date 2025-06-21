class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        if(s.size() == 0)
        {
            return true;
        }
        for(char c : s)
        {
            if(c == '(' || c == '{' || c== '[')
            {
                ss.push(c);
            }
            else if(ss.empty())
            {
                return false;
            }
            else if(c == ')' && ss.top() == '(')
            {
                ss.pop();
            }
            else if(c == ']' && ss.top() == '[')
            {
                ss.pop();
            }
            else if(c == '}' && ss.top() == '{')
            {
                ss.pop();
            }
            else{
                return false;
            }
        }
        if(ss.empty())
        {
            return true;
        }
        return false;
    }
};