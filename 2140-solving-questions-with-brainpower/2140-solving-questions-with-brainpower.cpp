class Solution {
public:
    long long rec(vector<vector<int>> &arr,int i,vector<long long> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        long long notTake = rec(arr,i+1,dp);
        long long take = arr[i][0] + rec(arr,i+arr[i][1]+1,dp);
        return dp[i] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,0);
        int n = questions.size();
        dp[n] = questions[n-1][0];
        for(int i = n-1; i>=0; i--){
            long long notTake = dp[i+1];
            long long take = 0;
            if(i+questions[i][1]+1<n){
                take = questions[i][0] + dp[i+questions[i][1]+1];
            }
            else{
                take = questions[i][0];
            }
            dp[i] = max(take,notTake);
        }
        return dp[0];
    }
};