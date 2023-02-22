//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        // Stack Approach:
        // vector<int> nge(n,1e9);
        // stack<int> st;
        // st.push(n-1);
        // for(int i = n-2; i>=0; i--){
        //     while(!st.empty() && arr[st.top()]<arr[i])st.pop();
        //     if(!st.empty()) nge[i] = st.top();
        //     st.push(i);
        // }
        // vector<int> ans(n-k+1);
        // int j = 0;
        // for(int i = 0; i<=n-k; i++){
        //     if(j<i) j= i;
        //     while(nge[j]< i+k){
        //         j = nge[j];
        //     }
        //     ans[i] = arr[j];
        // }
        // return ans;
        
        //Deque Approach:
        deque<int> dq;
        int j = 0;
        vector<int> ans(n-k+1);
        for(int i = 0; i<n; i++){
            if(!dq.empty() && dq.front() == i-k)dq.pop_front();
            while(!dq.empty() && arr[dq.back()]<arr[i])dq.pop_back();
            dq.push_back(i);
            if(i>=k-1){
                ans[j] = arr[dq.front()];
                j++;
            } 
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends