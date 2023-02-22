class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Stack solution:
        // vector<int> nge(nums.size(),1e9);
        // stack<int> st;
        // st.push(nums.size()-1);
        // for(int i = nums.size()-2; i>=0; i--){
        //     while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        //     if(!st.empty()) nge[i] = st.top();
        //     st.push(i);
        // }
        // vector<int> ans;
        // int j = 0;
        // for(int i = 0 ;i<=nums.size()-k; i++){
        //     if(j<i) j = i;
        //     while(nge[j] < i+k){
        //         j = nge[j];
        //     }
        //     ans.push_back(nums[j]);
        // }
        // return ans;
        
        //DeQeue solution:
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};