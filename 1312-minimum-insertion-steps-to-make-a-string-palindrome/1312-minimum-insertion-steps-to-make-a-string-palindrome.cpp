class Solution {
public:
    
    int rec(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = (1+rec(s1,s2,i-1,j-1,dp));
        else return dp[i][j] = (max(rec(s1,s2,i-1,j,dp),rec(s1,s2,i,j-1,dp)));
    }
    
    int minInsertions(string s) {
        string s2  = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,0));
        for(int i = 1; i<=s.length(); i++){
            for(int j = 1; j<=s.length(); j++){
                if(s[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int len = dp[s.length()][s.length()];
        return (s.length()-len);
    }
};