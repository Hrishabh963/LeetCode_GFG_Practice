class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j , n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }
        for(int i = j+1; i<n; i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};