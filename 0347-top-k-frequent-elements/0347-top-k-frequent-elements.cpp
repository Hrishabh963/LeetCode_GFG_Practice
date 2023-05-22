class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        for(int i = 0; i<k; i++){
            auto it  = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};