class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int index = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        for(auto it : temp){
            cout<<it<<" ";
        }
        return temp.size()>=3;
    }
};