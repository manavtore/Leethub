class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto& it:times){
           int u=it[0],v=it[1],w=it[2];
           graph[u].push_back({v,w}); 
        }

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
         vector<int> dist(n + 1, INT_MAX);
        dist[k]=0;
        pq.push({0,k});

    
        while(!pq.empty()){
            auto [time,u] =pq.top();
            pq.pop();

            if(time>dist[u])continue;

            for(auto& [v,w]:graph[u]){
                if(dist[u]+w <dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }

        }
        int totaldist = 0;

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            totaldist = max(totaldist, dist[i]);
        }

        return totaldist;
    }
};