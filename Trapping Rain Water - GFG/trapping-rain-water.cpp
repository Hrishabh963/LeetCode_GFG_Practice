//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long l[n],r[n];
        long long water = 0,lmax= 0,rmax = 0;
        for(int i = 1; i<n; i++){
            if(arr[i-1]>lmax){
                lmax = arr[i-1];
            }
            l[i] = lmax;
        }
        for(int i = n-2; i>=0; i--){
            if(arr[i+1]>rmax){
                rmax = arr[i+1];
            }
            r[i] = rmax;
        }
        for(int i = 1; i<n-1; i++){
            long long mini = min(l[i],r[i]);
            if(mini>arr[i]){
                water += mini-arr[i];
            }
        }
        return water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends