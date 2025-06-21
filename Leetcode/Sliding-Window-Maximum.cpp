class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq; // Keeps track of index number
        std::vector<int> answer;
        int left = 0;
        int right = 0;
        // Keeps track of sliding window and the range

        while(right<nums.size())
        {
            while(!dq.empty() && nums[right]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(right);
            if(left> dq.front())
            {
                dq.pop_front(); 
            }
            if(right+1>=k)
            {
                answer.push_back(nums[dq.front()]);
                left++;
            }
            right++;
        }
        return answer;
    }
};