class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
      
        string n = strs[0], m = strs[strs.size()-1],ans="";
        for(int i = 0; i<n.length(); i++){
           // cout<<n[i]<<"  "<<m[i]<<endl;
            if(n[i]==m[i])ans+=n[i];
            else break;
        }
        return ans;
    }
};