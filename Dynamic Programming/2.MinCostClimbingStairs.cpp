class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> v(n);
        
        v[n-1] = cost[n-1];
        v[n-2] = cost[n-2];
        
        for(int i=n-3;i>=0;i--)
        {
            v[i] = cost[i] + min(v[i+1], v[i+2]);
        }
        
        return min(v[0], v[1]);
        
    }
};
