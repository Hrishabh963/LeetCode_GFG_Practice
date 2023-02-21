//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
        vector<int> getlps(string s){
        	int len = 0;
        	int i = 1;
        	vector<int> lps(s.length());
        	while(i<s.length()){
        		if(s[i] == s[len]){
        			len++;
        			lps[i] = len;
        			i++;
        		}
        		else{
        			if(len!=0){
        				len = lps[len-1];
        			}
        			else{
        				lps[i] = 0;
        				i++;
        			}
        		}
        	}
        return lps;
}
    int minChar(string str){
        //Write your code here
    string temp = str;
    reverse(temp.begin(),temp.end());
	string curr = str+"$"+temp;
	vector<int> lps = getlps(curr);
	return (str.length() - lps.back());
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends