#include <queue>
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> queue_line;
        for(int i = 0; i< students.size(); i ++){
            queue_line.push(students[i]);
        }


        int i = 0; // Keeps track of the mismatches
        int j = 0; // Keeps track of the current top sandwhich
        while( j < sandwiches.size() && i!= queue_line.size()){
            if (queue_line.front() == sandwiches[j]){
                queue_line.pop(); // Student head of the line leaves
                i = 0 ;
                j +=1;
            }
            else{ // Mismatch
                int temp = queue_line.front();
                queue_line.pop();
                queue_line.push(temp);
                i += 1; // Increment mismatch

            }
        }
        if( i == 0){
            return 0;
        }
        else{
            return i;
        }  
    }
};