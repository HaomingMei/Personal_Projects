#include <cmath>
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0 ;
        int rep = std::ceil(std::log2(n));
        //std::cout << "Number of repetition: " << rep<< std::endl;
        for (int i = 0; i<= rep; i++ ){
           // std::cout << "Current n is :" << n << std::endl;
            if((n & (0x1)) == 1) { // Rightmost bits
                ans+=1;
            }
            n >>= 1;
           // std::cout << "Shifted n is :" << n << std::endl;
            //std::cout << "ans is: "<< ans << std::endl;
        }
        return ans;
    }
};