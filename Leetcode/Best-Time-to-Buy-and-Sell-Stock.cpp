class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int left =0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[left] >= prices[i]){
                left = i;
            }
            else{ // left is less than current
                maxProfit = std::max(maxProfit, prices[i] - prices[left] );
            }
        }
        return maxProfit;
    }
};