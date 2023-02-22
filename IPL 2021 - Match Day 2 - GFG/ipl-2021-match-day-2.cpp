//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> nge(n,1e9);
        stack<int> st;
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(!st.empty() && arr[st.top()]<arr[i])st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }
        vector<int> ans(n-k+1);
        int j = 0;
        for(int i = 0; i<=n-k; i++){
            if(j<i) j= i;
            while(nge[j]< i+k){
                j = nge[j];
            }
            ans[i] = arr[j];
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