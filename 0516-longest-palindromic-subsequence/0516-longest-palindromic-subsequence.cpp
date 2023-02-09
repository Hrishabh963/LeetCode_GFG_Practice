class Solution
{
    public:
        int longestPalindromeSubseq(string s)
        {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,0));
            for(int i = 1; i<=s.length(); i++){
                for(int j = 1; j<=s.length(); j++){
                    if(s[i-1] == s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            return dp[s.length()][s.length()];
        }
};