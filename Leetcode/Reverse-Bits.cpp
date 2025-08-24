class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        if(n ==0){

            return 0;
        }
        
        int rep = std::floor(log2(n)) +1;
        for(int i = 0; i<32; i++){
            ans <<= 1;
            if((n&1)==1){
                ans |= 0x1;
            }
            //std::cout << "Ans is: " << ans << std::endl;
            n >>= 1;
        }
        return ans;
    }
};