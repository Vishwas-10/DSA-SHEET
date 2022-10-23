class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        
        int n = values.size();
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> vis(n, 0);     
        return explorePaths(adj, values, vis, 0, values[0], maxTime);
    }
	
    int explorePaths(vector<vector<pair<int, int>>>& adj, vector<int>& values, vector<int>& vis, int node, int quality, int time) {
        
        int maxQuality = 0;
        
        if(node == 0) maxQuality = max(maxQuality, quality);
        
        vis[node]++;
        
        for(auto& [adjnode, wt] : adj[node]) {
            if(wt <= time)
            {
                int val = quality + (vis[adjnode] ? 0 : values[adjnode]);
                maxQuality = max(maxQuality, explorePaths(adj, values, vis, adjnode, val, time - wt));
            }
        }
        
        vis[node]--;
        
        return maxQuality;
    }
};