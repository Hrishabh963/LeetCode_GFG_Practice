//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int rec(int a,int n,int m){
        if(n==0)return 1;
        int res = rec(a,n/2,m);
        if(n&1){
            return (a*1LL*(res*res)%m)%m;
        }
        return (res*1LL*res)%m;
    }
        int modulo(string s,int m)
        {
            //code here
            long long num = 0;
            int i = s.length()-1;
            int power = 0; 
            while(i>=0){
                if(s[i]=='1'){
                    int pw = rec(2,power,m);
                    num = num+pw;
                }
                power++; i--;
            }
            return (int)(num%m);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends