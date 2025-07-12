#include <vector>
#include <string>
#include <algorithm>
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        std::vector<int> tp; 
        int time = 0;
        for (int i = 0; i < timePoints.size(); i++){ // Looping through the entire vector of strings    
            time = 0;
            for(int j = 0; j < 5; j++){
                if(j == 0){
                    time += (timePoints[i][j] - '0')*10*60;
                }
                else if (j==1){
                    time += (timePoints[i][j] - '0')*60;
                }
                else if(j==3){
                    time += (timePoints[i][j] - '0')*10;
                }
                else{
                    time += (timePoints[i][j] - '0');
                }
            }
            tp.push_back(time);


        }

        std::sort(tp.begin(), tp.end()); // Sorting in ascending order

        // Calculate the wrap around distance first
        int min = (1440-tp[tp.size()-1]) + tp[0]; // Wrap Again Distance First
        if(min == 0){
            return 0;
        }
        // Start iterating through the tp vector at i = 0
        // We can assume the left and right values of the current are the minmum time difference between current time and the rest of the time point values in the vector

        for (int i = 1; i<tp.size(); i++){
            if (tp[i] - tp[i-1] < min){
                min = tp[i] - tp[i-1];
            }
            if(min == 0){
                return 0;
            }
        }
        return min;

    }
};