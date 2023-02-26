class Solution {
public:
    int rec(string s1,string s2,int i,int j,vector<vector<int>>& dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return rec(s1,s2,i-1,j-1,dp);
        int insert = 1 + rec(s1,s2,i,j-1,dp);
        int del = 1 + rec(s1,s2,i-1,j,dp);
        int replace  = 1 + rec(s1,s2,i-1,j-1,dp);
        return dp[i][j] = min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i = 0 ;i<=word1.size(); i++){
            dp[i][0] = i;
        }
        for(int j = 0; j<=word2.size(); j++){
            dp[0][j] = j;
        }
        for(int i = 1; i<=word1.size(); i++){
            for(int j = 1; j<=word2.size(); j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};