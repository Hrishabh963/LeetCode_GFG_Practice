class Solution {
public:
    
    int find(vector<int> &arr,int i,int buy,vector<vector<int>> &dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        long profit = 0;
        if(buy){
            profit = max(find(arr,i+1,0,dp)-arr[i],find(arr,i+1,1,dp));
        }
        else{
            profit = max(find(arr,i+1,1,dp)+arr[i],find(arr,i+1,0,dp));
        }
        return dp[i][buy] = (int)profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return (int)find(prices,0,1,dp);
    }
};