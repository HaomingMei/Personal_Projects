#include <vector>
#include <algorithm> // For Sorting
#include <string>
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int minute_track = 0;
        std::vector<int> timePoint_Min;
       // std::cout << timePoints.size() << std::endl;

        for(int i = 0; i< timePoints.size();i++ ){
            //std::cout << timePoints[i] << std::endl;
            minute_track = 0;
            for(int j =0; j< 5; j++){
                //std::cout << timePoints[i][j] << std::endl;
                if(j == 0){
                    minute_track += (timePoints[i][j] - '0')*10*60;
                }
                else if(j == 1){
                    minute_track += (timePoints[i][j] - '0')*60;
                }
                else if(j == 3){
                    minute_track += (timePoints[i][j] - '0')*10;
                }
                else if(j == 4){
                    minute_track += (timePoints[i][j] - '0');
                }
            }
            timePoint_Min.push_back(minute_track);
            

        }

        std::sort(timePoint_Min.begin(), timePoint_Min.end());

        int min = (1440-timePoint_Min[timePoint_Min.size()-1])+timePoint_Min[0];
        if(min == 0){
            return 0;
        }
        for(int i = 1; i< timePoint_Min.size(); i++){
            timePoint_Min[i-1] =timePoint_Min[i] - timePoint_Min[i-1];
            if(timePoint_Min[i-1] == 0){
                return 0;
            }
            else if(timePoint_Min[i-1] <min){
                min = timePoint_Min[i-1];
            }

        }
        return min;

    }
};