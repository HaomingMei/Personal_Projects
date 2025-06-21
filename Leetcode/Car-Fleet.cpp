class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        // Number of Fleet we have by default is equal the number of cars
        std::priority_queue<std::pair<int, int>> cars;
        for(int i = 0; i<n; i++)
        {
            cars.push({position[i], speed[i]});
        }
        while(!cars.empty()){
            double time = (double)(target - cars.top().first) / cars.top().second;
            cars.pop();
       
            while(!cars.empty() && time>= (double)(target - cars.top().first) / cars.top().second)
            {
                cars.pop();
                n--;
            }
            
            
        }
        return n;
    }
};