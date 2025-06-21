
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        for(auto str: tokens)
        {
        
            // Push the Integers in first, else its operators
            if(str.size()>1 || isdigit(str[0]))
            {
                // -7
                // 348230
                st.push(stoi(str));
            }
            else{
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                // Detect operators
                if(str == "+")
                {
                    st.push(first+second);
                }
                else if(str == "-")
                {
                    st.push(first-second);
                }
                else if(str == "*")
                {
                    st.push(first*second);   
                }
                else{ // Division /
                    st.push(first/second);
                }
            }


        }
        return st.top();
    }

};