class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        vector<int> row(grid.size());
        for(int i = 0; i<grid.size(); i++){
            m[grid[i]]++;
        }
        int count = 0;
        for(int j = 0; j<grid.size(); j++){
            vector<int> col(grid.size());
            for(int i = 0 ;i<grid.size(); i++){
                col[i] = grid[i][j];
            }
            count+=m[col];
        }
        return count;
    }
};