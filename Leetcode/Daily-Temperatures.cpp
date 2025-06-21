class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> resultVector;
        resultVector.resize(temperatures.size());
        std::stack<std::pair<int,int>> st;
        
        for(int i = 0 ; i <temperatures.size() ; i++)
        {
           while(!st.empty() && temperatures[i] > st.top().first)
           {
               // Update the days (found warmer temperature day)
               resultVector[st.top().second] = i - st.top().second;
               st.pop();
           }
           st.push({temperatures[i], i});
        }
        
        // while(!st.empty())
        // {
        //     resultVector[st.top().second] = 0;
        //     st.pop();
        // }
        return resultVector;
    }
};