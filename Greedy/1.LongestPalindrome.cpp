class Solution {
public:
    int longestPalindrome(string str) {
        
        int n = str.size();
        
        int count = 0;
        
        // odd_count will keep track of is there any no. whose frequency is odd
        
        bool odd_count = false;
        
        // map will store the count of every characters
        
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[str[i]]++;
        }
        
        // iterate over map
        
        for(auto x : mp)
        {
            // if frequecy is even then we can take all the occurances
            
            if(x.second % 2 == 0)
            {
                count += x.second;
            }
            
            // if frequency is odd then take all the occurances except 1
            else
            {
                count += x.second - 1;
                
                odd_count = true;
            }
        }
        
        // if there is any number whose frequency is odd, then we can place that character in middle
      
        if(odd_count)
            count++;
        
        return count;
    }
};
