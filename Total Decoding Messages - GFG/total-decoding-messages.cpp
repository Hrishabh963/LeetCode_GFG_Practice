//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int mod = 1000000007;

 

 int solve(string str,int index,vector<int>& dp)

 {

     if(index<=0)return 1;

     if(dp[index]!=-1)return dp[index]%mod;

     int count = 0;

     if(str[index]>='1')

     {

         count = solve(str,index-1,dp);

     }

     if(index-1>=0)

     {

         if(str[index-1]=='1' || (str[index-1]=='2' && str[index]<'7'))

         {

             count +=solve(str,index-2,dp);    

         }

     }

    

     return  dp[index] = count%mod;

 }

 

 int CountWays(string str){

     

     int n = str.length();

     if(n==1 and str[0]!='0')return 1;

     

     vector<int> dp(n,-1);

     

     return solve(str,n-1,dp)%mod;

 }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends