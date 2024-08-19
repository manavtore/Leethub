class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        int MOD = 1e9 + 7;

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (time > dist[u]) continue;

            for (auto [v, w] : graph[u]) {
                long long distan = dist[u] + w;
                if (distan < dist[v]) {
                    dist[v] = distan;
                    pq.push({distan, v});
                    ways[v] = ways[u];
                } else if (distan == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};
