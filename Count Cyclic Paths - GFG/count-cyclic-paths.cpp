//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        // code here 
        int mod = 1e9 + 7;
        if(N == 0 || N == 1) return 0;
        if(N == 2) return 3;
        vector<vector<int>> dp(4,vector<int>(N+1,0));
        dp[0][0] = 1;
        for(int i =1; i<=N; i++){
            for(int j = 0; j<=3; j++){
                dp[j][i] = (dp[(j+1)%4][i-1] + dp[j][i])%mod;
                dp[j][i] = (dp[(j+2)%4][i-1] + dp[j][i])%mod;
                dp[j][i] = (dp[(j+3)%4][i-1] + dp[j][i])%mod;
            }
        }
        return dp[0][N];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends