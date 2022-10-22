class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        int dp[n][n];
        int c = 0;
        for(int k=1;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                dp[i][j] = 0;
                if(k == 1)dp[i][j] = 1;
                else if(k == 2 && s[i] == s[j])dp[i][j] = 1;
                else if(k>=3 && s[i] == s[j] && dp[i+1][j-1] == 1)dp[i][j] = 1;
                
                if(dp[i][j] == 1) c++;
            }
        }
        return c;
    }
};
