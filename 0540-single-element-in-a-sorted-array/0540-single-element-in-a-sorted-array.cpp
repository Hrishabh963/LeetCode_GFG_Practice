class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        while(l<h){
            int mid = l+(h-l)/2;
            if(nums[mid] == nums[mid+1]){
                mid = mid-1;
            }
            if((mid-l+1)%2!=0){
                h = mid;
            }
            else{
                l = mid+1;
            }
        }
        return nums[l];
    }
};