class Solution {
public:
    #define ll long long int
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ll n = nums.size();
        for(ll i = 0; i<n; i++){
            for(ll j = i+1; j<n; j++){
                ll target2 = nums[i]+nums[j];
                ll rem = target - (target2);
                ll low = j+1;
                ll high = n-1;
                while(low<high){
                    ll sum = nums[low]+nums[high];
                    if(sum<rem)low++;
                    else if(sum>rem)high--;
                    else{
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        while(low<high && nums[low] == temp[2])low++;
                        while(low<high && nums[high] == temp[3])high--;
                    }
                }
                while(j<n-1 && nums[j]==nums[j+1])j++;
                while(i<n-1 && nums[i]==nums[i+1])i++;
            }
        }
        return ans;
    }
};