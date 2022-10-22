class Solution {
public:
    int maxi = INT_MIN;
    void helper(vector<vector<int>> &mat , int m , int n , int cols , int idx , vector<int> &vis){
        if(cols == 0 or idx==n){
            int cnt = 0;
            for(int p = 0 ; p < m ; p++){
                bool check = true;
                for(int q = 0 ; q < n; q++){
                    // if cell is 1 and not visited then we cannot take this row
                    if(mat[p][q] == 1 and vis[q] == 0){
                        check = false;
                        break;
                    }
                }
                if(check) cnt++;
            }
            maxi = max(maxi,cnt);
            return;
        }
        
        // picking idx th column and marking column as visited
        vis[idx]=1;
        helper(mat,m,n,cols-1,idx+1,vis);
        vis[idx]=0;
        
        // not picking
        helper(mat,m,n,cols,idx+1,vis);
        return;
        
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> vis(n);
        
        helper(mat,m,n,cols,0,vis);
        return maxi;
    }
};