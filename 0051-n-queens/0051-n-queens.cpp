class Solution
{
    public:
    
        bool isValid(int row,int col,vector<string>&grid,int n)
    {
        // left check
        for(int i=0;i<col;i++)
        {
            if(grid[row][i]=='Q') return false;
        }
        // upper left check 
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(grid[i][j]=='Q') return false;
        }
        // lower left check
        for(int i=row,j=col;i<n && j>=0;i++,j--)
        {
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
        void solveNqueen(vector<string> &board, vector<vector< string >> &ans, int col, int n)
        {
            if (col == n)
            {
                ans.push_back(board);
                return;
            }
            for (int row = 0; row < n; row++)
            {
                if (isValid(row,col,board,n))
                {
                    board[row][col] = 'Q';
                    solveNqueen(board, ans, col + 1, n);
                    board[row][col] = '.';
                }
            }
        }
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < string>> ans;
        vector<string> board(n,string(n,'.'));
        solveNqueen(board, ans,0, n);
        return ans;
    }
};