class Solution {
public:
    
    int f(vector<int> &nums,int prev,int i){
        if(i==nums.size())return 0;
        int notTake = f(nums,prev,i+1);
        int take = 0;
        if(prev==-1 || nums[i]>nums[prev])
            take = 1 + f(nums,i,i+1);
        return max(notTake,take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i = n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                 int notTake = dp[i+1][prev+1];
                 int take = 0;
                 if(prev==-1 || nums[i]>nums[prev])
                    take = 1 + dp[i+1][i+1];
                 dp[i][prev+1] = max(notTake,take);
            }
        }
        return dp[0][-1+1];
    }
};