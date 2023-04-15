class Solution {
public:
    
    bool find(vector<int> &arr, int i,int target,vector<vector<int>> &dp){
        if(target==0)return true;
        if(i==0){
            return (arr[i] == target);
        }
        if(dp[i][target]!=-1)return dp[i][target];
        bool take = 0;
        if(arr[i]<=target) take = find(arr,i-1,target - arr[i],dp);
        bool notTake = find(arr,i-1,target,dp);
        return dp[i][target] = (take||notTake);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum%2 == 1)return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return find(nums,nums.size()-1,target,dp);
    }
};