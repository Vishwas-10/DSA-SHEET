class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        if(s2.size() > s1.size()) return longestCommonSubsequence(s2, s1);
        int n = s1.size(), m = s2.size();
        int dp[2][m+1];
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=m;i++) dp[0][i] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[!i%2][j] = s1[i-1] == s2[j-1] ? 1 + dp[i-1][j-1] : max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
        
    }
};
