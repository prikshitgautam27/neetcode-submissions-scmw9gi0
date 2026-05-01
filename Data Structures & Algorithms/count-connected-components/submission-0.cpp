class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

            vector<vector<int>>adj(n);
            vector<int> vis(n, false);

            int count=0;

            for(auto & edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    dfs(i, adj , vis);
                    count++;
                }
            }
            return count;
    }
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis ){
        vis[node]=true;

        for(auto & nei : adj[node]){
            if(!vis[nei]){
                dfs(nei, adj , vis);
            }
        }

    }
};
