class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, maxi = 0;
        while(j<nums.size()){
            k-= 1 - nums[j];
            if(k<0){
                k+=1-nums[i];
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};