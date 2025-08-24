class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int filled = 1;

        for(int i = n; i >= 1; i--){
            int numOnes = 0;
            int temp = i;
            int rep = std::ceil(std::log2(i));
            for (int j = 0; j <= rep ; j++){
                if((temp&0x1) == 1){
                    numOnes += 1;
                }
                temp>>=1;
            }
            temp = i;
            for (int j = 0; j <= rep ; j++){
                if(ans[temp] == 0 && temp !=0){
                    ans[temp] = numOnes;
                    filled +=1;
                }
                if((temp & 0x1)==1){
                    numOnes-=1;
                }
                temp>>=1;
                if(filled == n+1){
                    return ans;
                }
            }
            
           // ans.push_back(numOnes);
        }
        return ans;
    }
};