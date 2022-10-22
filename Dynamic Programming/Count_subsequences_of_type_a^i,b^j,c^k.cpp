class Solution{
  public:
    // s : given string
    // return the expected answer
    int mod = 1000000007;
    int fun(string &s){
        //code here
        int n = s.length();
        vector<vector<long long int>> dp(n+1, vector<long long int> (3));
        for(int i=1;i<=n;i++){
            char x = s[i-1];
            for(int j=0;j<3;j++){
                dp[i][j] = dp[i-1][j];
            }
            if (x=='a'){
                dp[i][0] = 2*dp[i-1][0] + 1;
            }else if(x=='b'){
                dp[i][1] = 2*dp[i-1][1] + dp[i-1][0];
            }else{
                dp[i][2] = 2*dp[i-1][2] + dp[i-1][1];
            }
            for(int j=0;j<3;j++){
                dp[i][j]%=mod;
            }
        }
        // for(int i=0;i<=n;i++){
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
        // }
        return dp[n][2];
    }
};