//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       vector<int> curr(n+1,0),next(n+1,0);
       for(int i = n-1; i>=0; i--){
           for(int j = i-1; j>=-1; j--){
               int len = 0 + next[j+1];
               if(j == -1 || arr[i]>arr[j]){
                   len = max(len,1 + next[i+1]);
               }
               curr[j+1] = len;
           }
           next = curr;
       }
       return next[0];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends