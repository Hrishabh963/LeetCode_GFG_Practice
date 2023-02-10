//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &nums, int k) {
        // Your code goes here
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int rem = k - (nums[i]+nums[j]);
                int low = j+1;
                int high = n-1;
                while(low<high){
                    int sum = nums[low]+nums[high];
                    if(sum<rem)low++;
                    else if(sum>rem)high--;
                    else{
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        while(low<high && nums[low] == temp[2])low++;
                        while(low<high && nums[high] == temp[3])high--;
                    }
                }
                while(j<n-1 && nums[j] == nums[j+1])j++;
                while(i<n-1 && nums[i] == nums[i+1])i++;
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends