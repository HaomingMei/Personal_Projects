class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        std::stack<std::pair<int, int>> st;
        // Height && starting Index
        if(heights.size() ==1){
            return heights[0];
        }
        else{
            st.push({heights[0],0});
        }
        for(int i = 1; i<heights.size(); i++){
            int currHeight = heights[i];
            if(!st.empty() && currHeight > st.top().first)
            {
                st.push({currHeight, i});
            }
            else if(!st.empty() && currHeight < st.top().first)
            {
                int temp;
                
                while(!st.empty() && currHeight < st.top().first){
                    // Update maxArea
                    int area = st.top().first * (i - st.top().second);
                    if(maxArea < area)
                    {
                        maxArea = area;
                    }
                    temp = st.top().second;
                    st.pop();
                }
                st.push({currHeight, temp});
            }
        }
        int size = heights.size();
        while(!st.empty())
        {

            int area = st.top().first * (size - st.top().second);
            if(maxArea < area)
            {
                maxArea = area;
            }
            st.pop();
        }
        return maxArea;
    }
};