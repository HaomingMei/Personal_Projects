#include <unordered_map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Review
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> ans;
        int temp;
        for(int j = nums2.size()-1; j >= 0; j--){
            temp = nums2[j];
            while(!st.empty() && temp>st.top()){
                st.pop();
            }
            if(!st.empty() && temp < st.top() ){
                mp[temp] = st.top();
            }
            else{
                mp[temp] = -1;
            }
            st.push(temp);

        }

        for (int i = 0; i < nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};