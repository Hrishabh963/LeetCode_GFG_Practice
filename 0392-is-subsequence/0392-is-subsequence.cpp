class Solution {
public:
    int f(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(i>=s.length() || j>=t.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = 1+f(s,t,i+1,j+1,dp);
        return dp[i][j] = f(s,t,i,j+1,dp);
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return f(s,t,0,0,dp)==s.length();
    }
};