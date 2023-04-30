class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int totalSubsets = (1<<nums.size());
        vector<vector<int>> ans;
        for(int masks = 0; masks<totalSubsets; masks++){
            vector<int> curr;
            for(int i = 0; i<nums.size(); i++){
                if(masks&(1<<i)) curr.push_back(nums[i]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};