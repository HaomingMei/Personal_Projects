class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Column
        for(int x = 0; x<9; x++)
        {
            std::unordered_map<char, int> columnMap;
            // Key: number, Value: repetition
            // If repetition > 1 then return false
            for(int y=0; y<9; y++)
            {
                // Check if value already exist
                if(board[y][x] != '.'){
                    auto searchColumn = columnMap.find(board[y][x]);
                    if(searchColumn != columnMap.end())
                    {
                        // Value exist already return false
                        return false;
                    }
                    else{
                        columnMap.insert({board[y][x],1});
                    }
                }
                    
               
            }
        }
        // Takes care of rows
        for(int y = 0; y<9; y++)
        {
            std::unordered_map<char, int> rowMap;
            // Key: number, Value: repetition
            // If repetition > 1 then return false
            for(int x=0; x<9; x++)
            {
                // Check if value already exist
                if(board[y][x] != '.')
                {
                    auto searchRow = rowMap.find(board[y][x]);
                    if(searchRow != rowMap.end())
                    {
                        // Value exist already return false
                        return false;
                    }
                    else{
                        rowMap.insert({board[y][x],1});
                    }
                }
            }
        }
        // 3x3 sub-boxes
        // 2d vector with a hashmap
        // 1d vector with a hashmap
        // pair is 3x3
        std::vector<std::vector<std::unordered_map<char,int>>> subMap(3, std::vector<std::unordered_map<char,int>>(3));

        for(int y =0; y<9; y++)
        {
            for(int x=0; x<9; x++)
            {
                if(board[y][x] != '.')
                {
                    auto search = subMap[std::floor(y/3)][std::floor(x/3)].find(board[y][x]);
                    if(search != subMap[std::floor(y/3)][std::floor(x/3)].end())
                    {
                        // Existed 
                        return false;
                    }
                    else
                    {
                        subMap[std::floor(y/3)][std::floor(x/3)].insert({board[y][x],1});
                    }
                }
                
            }
        }

        return true;

        

    }
};