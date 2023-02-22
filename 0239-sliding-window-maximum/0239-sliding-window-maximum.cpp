class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> nge(nums.size(),1e9);
        stack<int> st;
        st.push(nums.size()-1);
        for(int i = nums.size()-2; i>=0; i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }
        vector<int> ans;
        int j = 0;
        for(int i = 0 ;i<=nums.size()-k; i++){
            if(j<i) j = i;
            while(nge[j] < i+k){
                j = nge[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};