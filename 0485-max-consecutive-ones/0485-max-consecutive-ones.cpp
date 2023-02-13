class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr = 0;
        for(auto it : nums){
            if(it == 1)curr++;
            if(curr>maxi)maxi = max(maxi,curr);
            else if(it == 0)curr = 0;
        }
        return maxi;
    }
};