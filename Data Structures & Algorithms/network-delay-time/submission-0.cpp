class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(const auto & edge: times){
            adj[edge[0]].push_back({edge[1],edge[2]});

        }
        vector<int>dist(n+1 ,INT_MAX);
        dist[k]= 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});
        while(!pq.empty()){
            int d= pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(d> dist[u]) continue;
            for(auto & nei : adj[u]){
                int v= nei.first;
                int weight = nei.second;

                if(dist[u] + weight < dist[v]){
                    dist[v] = weight + dist[u];
                    pq.push({dist[v] , v});
                }


            }
        }


        int maxtime= INT_MIN;
                for(int i =1; i<=n;i++){
                    if(dist[i]==INT_MAX){
                        return -1;

                    }
                    maxtime= max(maxtime, dist[i]);
                }

        return maxtime;
    }
};