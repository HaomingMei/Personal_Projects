class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        if(size > h)
        {
            return 0;
        }
        
        
        
        int left= 1;
        int right= *max_element(piles.begin(), piles.end());
        if(size == 1)
        {
            return std::ceil(double(piles[0])/h);
        }
        int currentMin = right;
        while(left<=right)
        {
            int speed = (left + right )/2;
            long long hoursNeeded=0;
            for(int i=0; i<size; i++){ // Try for h hours
           
                hoursNeeded = std::ceil((double)piles[i]/speed) + hoursNeeded;
            }

            if(h >= hoursNeeded ){ // Speed is large could be decreased
                right = speed-1;
                if(speed<currentMin)
                {
                    currentMin = speed;
                }
            }
            else{ // h< hourNeeded
                left = speed+1;
            }
            // Check if all 0 or negative

                // works, update currentSpeed
                    // try go left
                // doesn't work, try go right
            
        }
        return currentMin;
    

    }
};