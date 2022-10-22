class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        int ans = 1;
        for(int i=2;i<n+1;i++)
        {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};
