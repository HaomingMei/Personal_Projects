#include <unordered_map>
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 2d Vector to track whether a spot on the board is used or not
        //vector<vector<int>> used(board.size(), vector<int>(board[0].size(), 0));
       // std::cout << "Number of Rows is " << board.size() <<std::endl;
        //std::cout << "Column Length is " << board[0].size() <<std::endl;
        unordered_map<char, int> boardFreq;
        unordered_map<char, int> wordFreq;
        int rowMax = board.size();
        int colMax = board[0].size();
        int numChar = word.size();
        if((word.size()) > board.size() * board[0].size()){
            return false;
        }
        for(int i = 0 ; i<rowMax; i++){
            for(int j = 0; j<colMax; j++){
                boardFreq[board[i][j]] += 1;
            }

        }
        for(int z = 0; z < numChar; z++){
            wordFreq[word[z]] += 1;
        }
        for(auto [c, num]: wordFreq){
            if(boardFreq[c] < num){
                return false; // For all of the characters, if board's freq is less than word's freq, then return
            }
        }
        // Optimization 2: We can start from either the first character of the last
        // Reason is that we begin dfs upon finding a match for either the start/end
        // If there is a of the starting char, then we might do a lot of dfs
        // Instead, we can start dfs on the less freq one, thus saving time from dfsing the unless ones

        if(wordFreq[word[0]] > wordFreq[word.back()]){
            std::reverse(word.begin(), word.end());
        }
        for(int i = 0; i < rowMax; i++){
            for(int j = 0; j < colMax; j++){
                if(board[i][j] == *word.begin() && solve(board, word, 0,i,j, rowMax, colMax)){
                    return true;
                }
            }
        }
        return false;

    }
    bool solve(vector<vector<char>>& board, string word, int index, int rowStart, int columnStart, int rowMax, int colMax)
    {
       // std::cout << "length of word is: " << word.size() <<std::endl;
       
        if(rowStart >= rowMax  && columnStart >= colMax){
            return false;
        }
        else if(rowStart < 0 || columnStart <0 || rowStart >= rowMax || columnStart >= colMax || board[rowStart][columnStart] != word[index]){
            return false;
        }
        else if((board[rowStart][columnStart] == word[index]) && (index + 1 >= word.size())){
            //std::cout << "Returning true base case " << std::endl;
            return true;
        }

        char old = board[rowStart][columnStart];
        board[rowStart][columnStart] = '!';
        if(index + 1 >= word.size()){
            return true;
        }
        // Down
        if (solve(board, word, index+1, rowStart+1, columnStart, rowMax, colMax) || (solve(board, word, index+1, rowStart-1, columnStart, rowMax, colMax))||(solve(board, word, index+1, rowStart, columnStart-1, rowMax, colMax)) || (solve(board, word, index+1, rowStart, columnStart+1, rowMax, colMax))){
            board[rowStart][columnStart] = old;
            return true;
        }

        board[rowStart][columnStart] = old;
        return false;
    }
};
