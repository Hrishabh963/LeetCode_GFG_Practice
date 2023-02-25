class Solution {
public:
//     int rec(vector<int> &arr,int i){
//         if(i<0)return 1;
//         if(i == 0)return arr[i];
//         int left =1;
//         left*=rec(arr,i-1);
//         int right = 1;
//         right*= arr[i]*rec(arr,i-1);
//         return max(left,right);
          
//     }
    int maxProduct(vector<int>& nums) {
        //vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),1));
        int maxi = INT_MIN;
        int curr = 1;
        for(int i = 0; i<nums.size(); i++){
            curr*= nums[i];
            if(curr>maxi){
                maxi = max(maxi,curr);
            }
            if(curr==0){
                curr = 1;
            }
        }
        curr = 1;
        //Traverse again from backwards to check for a subarray before a 0 or negative integer for ex [3,-1,4]
        for(int i = nums.size()-1; i>=0; i--){
            curr*= nums[i];
            if(curr>maxi){
                maxi = max(maxi,curr);
            }
            if(curr==0){
                curr = 1;
            }
        }
        return maxi;
    }
};