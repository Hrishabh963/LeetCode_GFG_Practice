class Solution {
public:
    
    int f(vector<int> &prices,int i,int currTrans,int cap,vector<vector<int>> &dp){
        if(i==prices.size() || currTrans == 2*cap) return 0;
        if(dp[i][currTrans]!=-1)return dp[i][currTrans];
        if(currTrans%2==0){
            return dp[i][currTrans] = max(-prices[i]+f(prices,i+1,currTrans+1,cap,dp),f(prices,i+1,currTrans,cap,dp));
        }
        return dp[i][currTrans] = max(prices[i]+f(prices,i+1,currTrans+1,cap,dp),f(prices,i+1,currTrans,cap,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(5,-1));
        return f(prices,0,0,2,dp);
    }
};