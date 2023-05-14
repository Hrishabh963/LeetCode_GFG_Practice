class Solution {
public:
    int f(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = nums[i];
        int index = i+1;
        while(index<nums.size() && nums[index]==nums[i]){
            ans+=nums[index];
            index++;
        }
        int ind = index;
        while(index<nums.size() && nums[index]==nums[i]+1){
            index++;
        }
        return dp[i] = max(ans+f(nums,index,dp),f(nums,ind,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};