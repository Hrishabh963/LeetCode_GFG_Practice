class Solution {
public:
    int bsearch(vector<int> &nums,int k,bool isFirst){
        int ans = -1;
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid] == k){
                ans = mid;
                if(isFirst) h = mid-1;
                else l = mid+1;
            } 
            else if(k>nums[mid]) l = mid+1;
            else h = mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = bsearch(nums,target,true);
        int l = bsearch(nums,target,false);
        return {f,l};
    }
};