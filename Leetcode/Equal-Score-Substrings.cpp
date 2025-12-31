class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(char c: s){
            sum += c-'a' +1;
        }
        if(sum%2 != 0 ){
            return false;
        }
        int target = sum/2;

        int l = 0;
        int r = s.size()-1;
        while(l<= r){
            int m = (l+r)/2;
            int temp = 0;
            for(int i = 0; i <= m ; i++){
                temp += s[i]-'a' + 1;
                if(temp == target){
                    return true;
                }
            }
            //std::cout << temp << std::endl;
            if(temp < target){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return false;
    }
};