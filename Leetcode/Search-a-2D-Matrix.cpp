class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();

        // Binary Search by Rows
        int upper =0;
        int lower = rowSize-1;
        int mid;
        while(upper<= lower)
        {
            mid = upper + (lower-upper)/2;

            if(matrix[mid][0] == target)
            {
                return true;
            } // Potential row
            else if(matrix[mid][0] < target && (mid== rowSize-1 || matrix[mid+1][0] > target))
            {
                // Binary Search the row
                int left = 0;
                int right = columnSize-1;
                int rowMiddle ;
                while(left<= right)
                {
                    rowMiddle = left + (right-left)/2;
                    if(matrix[mid][rowMiddle] == target)
                    {
                        return true;
                    }
                    else if(matrix[mid][rowMiddle] <target)
                    {
                        // Serach right
                        left = rowMiddle+1;
                    }
                    else{
                        // search left
                        right = rowMiddle-1;
                    }
                }
                return false;
            }
            else if(target > matrix[mid][0])
            {
                // Search down
                upper = mid+1;
            }
            else if(target < matrix[mid][0])
            {
                lower = mid-1;
            }
        }
        return false;
    }
};