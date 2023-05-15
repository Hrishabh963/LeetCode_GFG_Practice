class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
       
        if(dp[i][j] != -1) return dp[i][j];
        
        int first = 0, second = 0, third = 0;
        if(i>=1 and j<m-1 and grid[i][j] < grid[i - 1][j + 1])
            first = 1 + dfs(i - 1, j + 1, n, m, grid, dp);
        if(j<m-1 and grid[i][j] < grid[i][j + 1])
            second = 1 + dfs(i, j + 1, n, m, grid, dp);
        if(i<n-1 and j<m-1 and grid[i][j] < grid[i + 1][j + 1]) 
            third = 1 + dfs(i + 1, j + 1, n, m, grid, dp);
        return dp[i][j] = max(first,max(second,third));
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int j=0; j<n; j++) {
            ans = max(ans, dfs(j, 0, n, m, grid, dp));
        }
        return ans;
        
    }
};