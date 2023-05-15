class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes = 1 , l = 0, r = 0,maxi=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeroes--;
            }
            while(zeroes<0){
                if(nums[l]==0)zeroes++;
                l++;
            }
            maxi = max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};