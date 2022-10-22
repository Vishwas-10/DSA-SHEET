class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v[n-1] = nums[n-1];
        if(n == 1) return v[0];
        v[n-2] = max(nums[n-2],nums[n-1]);
        if(n == 2) return v[n-2];
        for(int i=n-3;i>=0;i--)
        {
            v[i] = max(nums[i] + v[i+2], v[i+1]);
        }
        return v[0];
        
    }
};
