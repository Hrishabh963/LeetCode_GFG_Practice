class Solution {
public:
    
//     bool findMemo(vector<int> &arr, int i,int target,vector<vector<int>> &dp){
//         if(target==0)return true;
//         if(i==0){
//             return (arr[i] == target);
//         }
//         if(dp[i][target]!=-1)return dp[i][target];
//         bool take = 0;
//         if(arr[i]<=target) take = find(arr,i-1,target - arr[i],dp);
//         bool notTake = find(arr,i-1,target,dp);
//         return dp[i][target] = (take||notTake);
//     }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum%2 == 1)return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,0));
        for(int i = 0; i<nums.size(); i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i<nums.size(); i++){
            for(int t = 1; t<=target; t++){
                bool take = 0;
                if(nums[i]<=t) take = dp[i-1][t-nums[i]];
                bool notTake = dp[i-1][t];
                dp[i][t] = take||notTake;
            }
        }
        return dp[nums.size()-1][target];
    }
};