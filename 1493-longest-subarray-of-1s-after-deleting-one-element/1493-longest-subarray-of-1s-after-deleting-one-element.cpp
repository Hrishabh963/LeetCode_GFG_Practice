class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes = 1 , l = 0, r = 0,maxi=0;
        while(r<nums.size()){
            zeroes-= 1 - nums[r];
            if(zeroes<0){
                zeroes+=1-nums[l];
                l++;
            }
            maxi = max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};