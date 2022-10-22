class Solution {
public:
    int n;
    int max_operations;
    int ans = 0;
    vector <bool> seen;
    vector <vector <int>> wish; //to store the array of GCDs
    int maxScore(vector<int>& nums) {
        
        n = nums.size();
        max_operations = n / 2;
        
        seen.resize(n, false);
        
        vector <int> sum;
        
        solve(nums, 0, 0, sum);
        
        ans = 0;
        int interim = 0;
        
        for(int i = 0; i < wish.size(); i++) // this is to get the answer from each array we have 
		//in wish and then taking the maximum of it.
        {
            sort(wish[i].begin(), wish[i].end());
            
            for(int j = 0; j < wish[i].size(); j++)
                interim += (j + 1) * wish[i][j];
            
            ans = max(ans, interim);
            interim = 0;
        }
        
        return ans;
    }
    
    void solve(vector <int>& nums, int interim, int pos, vector <int>& sum)
    {
        if(pos == nums.size())
        {
            if(interim >= ans)
            {
                if(interim > ans) // this condition is true then we have a completely different 
				//answer altogether, that is why we need to clear the array wish here
                    wish.clear();
                
                wish.push_back(sum); //add the new array sum to wish
                ans = interim;
            }
            return;
        }
        
        if(seen[pos])
            return solve(nums, interim, pos + 1, sum); //if number already taken move forward
        
        seen[pos] = 1;
            
        for(int a = pos + 1; a < n; a++)   // trying every possibility
            if(!seen[a])
            {
                seen[a] = 1;
                int x = gcd(nums[pos], nums[a]);
                sum.push_back(x);
                
                solve(nums, interim + x, pos + 1, sum);
                
                sum.pop_back();
                seen[a] = 0;
            }
            
        seen[pos] = 0;
        }
    }
};