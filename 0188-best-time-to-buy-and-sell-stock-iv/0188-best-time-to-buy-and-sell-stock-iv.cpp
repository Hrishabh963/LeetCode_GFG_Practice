class Solution {
public:
    
    // int rec(vector<int> &arr,int i,int transactions,int k,vector<vector<int>> &dp){
    //     if(i==arr.size() || transactions==2*k) return 0;
    //     if(dp[i][transactions]!=-1)return dp[i][transactions];
    //     if(transactions % 2 == 0){
    //         return dp[i][transactions] = max(-arr[i]+rec(arr,i+1,transactions+1,k,dp),rec(arr,i+1,transactions,k,dp));
    //     }
    //     return dp[i][transactions] = max(arr[i]+rec(arr,i+1,transactions+1,k,dp),rec(arr,i+1,transactions,k,dp));
    // }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2*k+1,0));
        for(int i = prices.size()-1; i>=0; i--){
            for(int transactions = 2*k-1; transactions>=0; transactions--){
                if(transactions % 2 == 0){
                    dp[i][transactions] = max(-prices[i]+dp[i+1][transactions+1],dp[i+1][transactions]);
                }
               else dp[i][transactions] = max(prices[i]+dp[i+1][transactions+1] ,dp[i+1][transactions] );
            }
        }
        return dp[0][0];
    }
};