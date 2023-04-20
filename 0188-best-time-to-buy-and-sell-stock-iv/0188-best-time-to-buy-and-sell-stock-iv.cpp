class Solution {
public:
    
    int rec(vector<int> &arr,int i,int transactions,int k,vector<vector<int>> &dp){
        if(i==arr.size() || transactions==2*k) return 0;
        if(dp[i][transactions]!=-1)return dp[i][transactions];
        if(transactions % 2 == 0){
            return dp[i][transactions] = max(-arr[i]+rec(arr,i+1,transactions+1,k,dp),rec(arr,i+1,transactions,k,dp));
        }
        return dp[i][transactions] = max(arr[i]+rec(arr,i+1,transactions+1,k,dp),rec(arr,i+1,transactions,k,dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*k+1,-1));
        return rec(prices,0,0,k,dp);
    }
};