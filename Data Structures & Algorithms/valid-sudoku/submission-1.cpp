class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        unordered_map<int, unordered_set<char>> col_map;
        col_map.reserve(9);
        unordered_map<int, unordered_set<char>> row_map;
        row_map.reserve(9);

        unordered_map<int, unordered_set<char>> sqr_map;
        sqr_map.reserve(9);

        for(int i =0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                {continue;}

                auto it = row_map.find(i);
                if(it != row_map.end() && it->second.find(board[i][j]) != it->second.end())
                {
                    return false;
                }

                it = col_map.find(j);
                if(it != col_map.end() && it->second.find(board[i][j]) != it->second.end())
                {
                    return false;
                }

                int coord = (i/3)*3 + (j/3);

                it = sqr_map.find(coord);
                if(it != sqr_map.end() && it->second.find(board[i][j]) != it->second.end())
                {
                    return false;
                }

                row_map[i].insert(board[i][j]);
                col_map[j].insert(board[i][j]);
                sqr_map[coord].insert(board[i][j]);

            }
        }

        return true;
    }
    
};
