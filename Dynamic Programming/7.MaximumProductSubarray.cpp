class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(auto x : nums) ans = max(ans,x);
        
        int currmax = 1, currmin = 1;
        
        for(auto x : nums)
        {
            int t1 = currmax * x, t2 = currmin * x;
            currmax = max(t1,max(t2,x));
            currmin = min(t1,min(t2,x));
            ans = max(ans,currmax);
        }
        return ans;
        
    }
};
