class Solution {
public:
    
//     int rec(vector<int> &arr,int i,int n,int buy,int cap,vector<vector<vector<int>>> &dp){
//         if(cap==0)return 0;
//         if(i==n)return 0;
//         if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
//         int profit = 0;
//         if(buy){
//             profit = max(rec(arr,i+1,n,0,cap,dp)-arr[i],rec(arr,i+1,n,1,cap,dp));
//         }
//         else{
//             profit = max(rec(arr,i+1,n,1,cap-1,dp)+arr[i],rec(arr,i+1,n,0,cap,dp));
//         }
//         return dp[i][buy][cap] = profit;
//     }
    
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int notpick,pick;
        vector<vector<vector<int>>> dp (n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j){
                        notpick = 0 + dp[i+1][1][k];
                        pick = v[i] + dp[i+1][0][k-1];
                    }
                    else{
                        notpick = 0 + dp[i+1][0][k];
                        pick = -v[i] + dp[i+1][1][k];
                    }
                    dp[i][j][k] = max(pick,notpick);
                }
            }
        }
        return dp[0][0][2];
    }
};