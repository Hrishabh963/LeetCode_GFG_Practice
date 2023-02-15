class Solution {
public:
    vector<int> addToArrayForm(vector<int>& arr, int k) {
        for(int i = arr.size()-1; i>=0; i--){
            int sum = arr[i] + k;
            arr[i] = sum%10;
            k = sum/10;
        }
        while(k){
            arr.insert(arr.begin(),k%10);
            k = k/10;
        }
        return arr;
    }
};