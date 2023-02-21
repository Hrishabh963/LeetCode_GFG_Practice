//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string s1){
        // code here 
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    vector<int> prev(s1.length()+1,0),curr(s1.length()+1,0);
    for(int i = 1; i<=s1.length(); i++){
        for(int j = 1; j<=s1.length(); j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }
    int len = prev[s1.length()];
    //cout<<len<<endl;
    return (s1.length() - len);
        
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends