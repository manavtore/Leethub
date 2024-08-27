class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double succ = succProb[i];
            graph[u].push_back({v,succ});
            graph[v].push_back({u,succ});
        }
          
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);

        pq.push({1.0,start});
        maxProb[start]=1.0;

        while(!pq.empty()){
            int node = pq.top().second;
            auto prob = pq.top().first;
            pq.pop();

            if(node==end) return prob;

            for(const auto& edge:graph[node]){
                int neighbour = edge.first;
                auto edgeprob = edge.second;
                auto newProb = prob * edgeprob;
                if(newProb>maxProb[neighbour]){
                    maxProb[neighbour] = newProb;
                    pq.push({newProb,neighbour});
                }
                
            }

        }

        return 0.0;

    }
};