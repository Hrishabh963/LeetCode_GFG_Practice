class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<nums.size(); i++){
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
            int sum = nums[i]+nums[low]+nums[high];
            if(sum<0)low++;
            else if(sum>0)high--;
            else{
                ans.push_back({nums[i],nums[low],nums[high]});
                int low_last = nums[low];
                int high_last = nums[high];
                while(low<high && nums[low] == low_last) low++;
                while(low<high && nums[high] == high_last) high--;
            }
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};