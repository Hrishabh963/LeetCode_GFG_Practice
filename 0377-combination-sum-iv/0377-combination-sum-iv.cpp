class Solution {
public:
    int f(vector<int> &nums,int i,int target,vector<vector<int>> &dp){
        if(target==0)return 1;
        if(i>=nums.size()) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = 0, take = 0;
        notTake = f(nums,i+1,target,dp);
        if(nums[i]<=target) take = f(nums,0,target - nums[i],dp);
        return dp[i][target] = take+notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return f(nums,0,target,dp);
    }
};