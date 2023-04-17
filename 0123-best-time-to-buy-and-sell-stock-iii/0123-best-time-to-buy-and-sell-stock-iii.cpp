class Solution {
public:
    
    int rec(vector<int> &arr,int i,int n,int buy,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0)return 0;
        if(i==n)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(rec(arr,i+1,n,0,cap,dp)-arr[i],rec(arr,i+1,n,1,cap,dp));
        }
        else{
            profit = max(rec(arr,i+1,n,1,cap-1,dp)+arr[i],rec(arr,i+1,n,0,cap,dp));
        }
        return dp[i][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(prices,0,prices.size(),1,2,dp);
        
    }
};