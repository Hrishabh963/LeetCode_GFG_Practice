class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
                int low = i+1;
                int high = n-1;
                while(low<high){
                    int sum = nums[i]+nums[low]+nums[high];
                    if(sum<0)low++;
                    else if(sum>0)high--;
                    else{
                        ans.push_back({nums[i],nums[low],nums[high]});
                        int currl = nums[low];
                        int currh = nums[high];
                        while(low<high && nums[low] == currl)low++;
                        while(low<high && nums[high] == currh)high--; 
                    }
                }
            while(i<n-1 && nums[i] == nums[i+1])i++;
            }
        return ans;
        }
};