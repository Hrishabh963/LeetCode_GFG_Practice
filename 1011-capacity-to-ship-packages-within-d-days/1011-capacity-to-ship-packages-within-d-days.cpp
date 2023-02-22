class Solution {
public:
    
    int getDays(vector<int> &weights,int capacity){
        int days = 1;
        int currCap = 0;
        for(auto it : weights){
            currCap+=it;
            if(currCap>capacity){
                days++;
                currCap = it;
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = INT_MIN;
        int maxi = 0;
        for(auto it : weights){
            mini = max(mini,it);
            maxi+=it;
        }
        int ans = 0;
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
            int daysReq = getDays(weights,mid);
            if(daysReq>days){
                mini = mid+1;
            }
            else{
                ans = mid;
                maxi = mid-1;
            }
        }
        return ans;
    }
};