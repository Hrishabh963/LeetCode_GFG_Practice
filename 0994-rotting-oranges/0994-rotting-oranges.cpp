class Solution {
public:
    // void dfs(vector<vector<int>> &grid,int i,int j,int min){
    //     if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0) return;;
    //     grid[i][j] = min;
    //     dfs(grid,i+1,j,min);
    //     dfs(grid,i,j+1,min);
    //     dfs(grid,i-1,j,min);
    //     dfs(grid,i,j-1,min);
    // }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int visited[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else visited[i][j] = 0;
            }
        }
        int ans = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans,time);
            for(int i = 0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol] !=2 && grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = 2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};