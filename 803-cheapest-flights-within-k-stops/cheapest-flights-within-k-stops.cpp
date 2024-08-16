class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }


        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        vector<int> dis(n,1e9);

        dis[src]=0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int Node = it.second.first;
            int stops = it.first;
            int weight = it.second.second;

            if(stops>k) continue;
            for(auto iter:adj[Node]){
                int adjNode = iter.first;
                int price = iter.second;

                if(weight + price <= dis[adjNode] && stops<=k){
                    dis[adjNode] = weight + price;
                    q.push({stops+1,{adjNode,weight+price}});
                }
                
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];

    }
};