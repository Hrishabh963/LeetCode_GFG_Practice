class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int winner = 0;
        for(int i  = 0; i<nums.size(); i++){
            if(count == 0){
                winner = nums[i];
            }
            if(winner == nums[i]){
                count++;
            }
            else count--;
        }
        return winner;
    }
};