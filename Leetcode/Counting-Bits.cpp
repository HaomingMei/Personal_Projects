class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i<= n; i++){
            int numOnes = 0;
            int temp = i;
            int rep = std::ceil(std::log2(i));
            for (int j = 0; j <= rep ; j++){
                if((temp&0x1) == 1){
                    numOnes += 1;
                }
                temp>>=1;
            }
            ans.push_back(numOnes);
        }
        return ans;
    }
};