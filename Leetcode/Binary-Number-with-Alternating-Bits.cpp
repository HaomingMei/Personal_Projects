#include <cmath> // For log
class Solution {
public:
    bool hasAlternatingBits(int n) {

        int prev = (n&0x1);
        //std::cout<< prev << std::endl;
        int current = 0;
        //float temp_value = static_cast<float>(n);
       // std::cout<< temp_value << std::endl;
       int num_iter = 0;
       if(n%2){
        num_iter = static_cast<int>(std::log2(n));
       }
       else{

        num_iter =static_cast<int>((std::ceil(std::log2(n))));
       }
       // std::cout<< num_iter << std::endl;
     

        for(int i = 0; i<num_iter; i++){
            n = n>>1;
            current = (n&0x1); // Mask current least significant 
            if ( current != prev){
                prev = current;
            }
            else{
                return false;
            }

        }
        return true;
       // std::cout<< num_iter << std::endl;

    }
};