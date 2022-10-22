class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int dp[n][n];
        int a = 0, c=1;
        for(int k=1;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                dp[i][j] = 0;
                if(k == 1) dp[i][j] = 1;
                if(k == 2 && s[i]==s[i+1])
                {
                    dp[i][i+1] = 1;
                    a = i;
                    c = k;
                    
                }
                if(k>=3)
                {
                    if(s[i] == s[j] && dp[i+1][j-1] == 1)
                    {
                        dp[i][j] = 1;
                        if(k>c)
                        {
                            a = i;
                            c = k;
                        }
                    }
                }
            }
        }
        return s.substr(a,c);
        
    }
};
