#include <queue>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        int stone1;
        int stone2;
        while(pq.size() != 1)
        {
            //* Grab the top 2
            stone1 = pq.top();
            pq.pop();
            stone2 = pq.top();
            pq.pop();

            if(stone1 != stone2){
                pq.push(abs(stone1-stone2));
            }
            if(pq.size()<=1){
                break;
            }
           
        }
        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }

       
    }
};