//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        sort(arr,arr+n);
        for(int i = 0; i<n; i++){
            int low = i+1;
            int high = n-1;
            int target = X - arr[i];
            while(low<high){
                int sum = arr[low]+arr[high];
                if(sum<target)low++;
                else if(sum>target) high--;
                else{
                    return true;
                }
            }
            while(i<n-1 && arr[i] == arr[i+1])i++;
        }
        return false;
    }
    
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends