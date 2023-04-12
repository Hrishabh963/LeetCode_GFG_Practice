class Solution {
public:
    
    bool(isSafe(vector<vector<char>> &board,int i,int j,char k)){
        for(int r = 0; r<9; r++){
            if(board[r][j]==k)
                return false;
            if(board[i][r]==k)
                return false;
            if(board[3*(i/3)+r/3][3*(j/3)+r%3]==k)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k<=9; k++){
                        if(isSafe(board,i,j,k+'0')){
                            board[i][j] = k+'0';
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;    //No number can be placed here,return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};