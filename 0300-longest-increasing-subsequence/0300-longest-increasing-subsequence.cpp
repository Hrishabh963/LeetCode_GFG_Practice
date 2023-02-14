class Solution {
public:
    int rec(vector<int> &arr,int curr,int prev,vector<vector<int>> &dp){
        if(curr == arr.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int len = 0 + rec(arr,curr+1,prev,dp);
        if(prev == -1 || arr[curr]>arr[prev]){
            len = max(len,1 + rec(arr,curr+1,curr,dp));
        }
        return dp[curr][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return rec(nums,0,-1,dp);
    }
};