class Solution {
public:
/* Time coplexity = O(n) || Space complexity = O(1). */
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int x=n-1; //nearest variable from where we can reach (n-1)th index.(Greedy approach)
        bool ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+nums[i]>=x) //condition that can we reach to x from i.
            {
                ans=1;
                x=i; // update the value of x as we got a nearer point.
            }
            else ans=0;
        }
        return ans;
    }
};