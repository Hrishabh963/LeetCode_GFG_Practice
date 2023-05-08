class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        bool isOdd = true;
        if(n%2==0) isOdd = false;
        int i = 0, j = 0;
        while(i<n && j<n){
            ans+= mat[i][j];
            i++; j++;
        }
         i = 0 , j = n-1;
        while(i<n && j>=0){
            if(i==j && isOdd){
                i++; j--;
            }
            else {
                ans+=mat[i][j];
                i++; j--;
            }
        }
        return ans;
    }
};