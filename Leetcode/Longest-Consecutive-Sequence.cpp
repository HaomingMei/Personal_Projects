class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Keep track of longest consecutive elements
        std::priority_queue<int> pq;
        std::priority_queue<int> longest;
       
        
        for(int i =0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        // pq ordered largest to least from 0th index
        if(pq.empty())
        {
            return 0;
        }
        int count = 1;
        longest.push(1);
        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            if(top - 1 == pq.top())
            {
                count++;
            }
            else if(pq.top() == top)
            {
                continue;
            }
            else // handles not consective case
            {

                count = 1;
            }
            longest.push(count);
        }
        
        return longest.top();
    }
};