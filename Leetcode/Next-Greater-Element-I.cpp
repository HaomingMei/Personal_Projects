class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> mp;
            stack<int> mystack;

            for(int i=nums2.size()-1; i>=0; i--){
            while(!mystack.empty() && mystack.top() < nums2[i]){
                mystack.pop();
            }
            if(mystack.empty() || mystack.top() < nums2[i]) mp[nums2[i]] = -1;
            else mp[nums2[i]] = mystack.top();
            mystack.push(nums2[i]);
            }

            vector<int> solution;
            for(int i=0; i<nums1.size(); i++){
            solution.push_back(mp[nums1[i]]);
            }


            return solution;
        
    }
};