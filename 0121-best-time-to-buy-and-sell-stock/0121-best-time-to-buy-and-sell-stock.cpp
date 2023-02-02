class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell  = INT_MIN;
        for(auto it : prices){
            buy = min(buy,it);
            sell = max(sell,it-buy);
        }
        return sell;
    }
};