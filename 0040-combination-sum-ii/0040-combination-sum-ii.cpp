class Solution {
public:
    void func(vector<int> &arr,int i,int n,vector<vector<int>> &ans,vector<int> &temp,int key){
        
            if(key == 0){
                ans.push_back(temp);
                return;
            }
        
        for(int j = i; j<arr.size(); j++){
            if(j>i && arr[j] == arr[j-1]) continue;
            if(arr[j]>key) break;
            temp.push_back(arr[j]);
            func(arr,j+1,n,ans,temp,key - arr[j]);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(candidates,0,candidates.size(),ans,temp,target);
        return ans;
    }
};