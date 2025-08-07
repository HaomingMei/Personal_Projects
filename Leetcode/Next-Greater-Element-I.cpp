class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> result;
            int indicator = 0;
            for(int i = 0; i <nums1.size(); i++){
                int temp1 = nums1[i];
                for(int j = 0; j < nums2.size(); j++){
                    if(indicator == 1){
                        if(temp1<nums2[j]){
                            indicator = 0;
                            result.push_back(nums2[j]);
                            break;
                        }
                        if(j== nums2.size()-1){
                            indicator = 0;
                            result.push_back(-1);
                        }
                        continue;
                    }
                    if(temp1 == nums2[j]){
                        indicator = 1;
                    }
                    if(j== nums2.size()-1){
                        indicator = 0;
                        result.push_back(-1);
                    }

                    
                }
            }
            return result;
    }
};