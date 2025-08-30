class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 2d Vector to track whether a spot on the board is used or not
        vector<vector<int>> used(board.size(), vector<int>(board[0].size(), 0));
       // std::cout << "Number of Rows is " << board.size() <<std::endl;
        //std::cout << "Column Length is " << board[0].size() <<std::endl;
        return solve(board, word, used, 0, 0, 0 );

    }
    bool solve(vector<vector<char>>& board, string word, vector<vector<int>>& used, int index, int rowStart, int columnStart)
    {
       // std::cout << "length of word is: " << word.size() <<std::endl;
       
        if(rowStart >= board.size() && columnStart >= board[0].size()){
            return false;
        }
        else if(rowStart < 0 || columnStart <0 || rowStart >= board.size() || columnStart >= board[0].size()){
            return false;
        }
        else if((board[rowStart][columnStart] == word[index]) && (used[rowStart][columnStart] == 0) && (index + 1 >= word.size())){
            //std::cout << "Returning true base case " << std::endl;
            return true;
        }

        for(int row = rowStart; row< board.size(); row++){
            for(int column = columnStart;  column< board[0].size(); column++){
                if((board[row][column] == word[index]) && (used[row][column] == 0)){ // Start the sequence / Continue
                    used[row][column] = 1;
                    if(index + 1 >= word.size()){
                        return true;
                    }
                    // Down
                    if (solve(board, word, used, index+1, row+1, column)){
                        return true;
                    }
                    //std::cout << "Down no match " << std::endl;
                    // Up
                    if(solve(board, word, used, index+1, row-1, column)){
                        return true;
                    }
                    //std::cout << "Up no match " << std::endl;
                    // Left 
                    if(solve(board, word, used, index+1, row, column-1)){
                        return true;
                    }
                    //std::cout << "Left no match " << std::endl;
                    //Right
                    if(solve(board, word, used, index+1, row, column+1)){
                        return true;
                    }
                    //std::cout << "Right no match " << std::endl;
                    used[row][column] = 0;
                    if(index != 0){
                        return false;
                    }
                    //return false;
                }
                else{
                    if(index != 0){
                        return false;
                    }
                }
               
            }
        }
        //used[rowStart][columnStart] =0;
        // You checked everything but there is not a match
        return false;
    }
};
