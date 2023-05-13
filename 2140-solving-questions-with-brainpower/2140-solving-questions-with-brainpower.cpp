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
        vector<long long> dp(questions.size()+1,-1);
        return rec(questions,0,dp);
    }
};