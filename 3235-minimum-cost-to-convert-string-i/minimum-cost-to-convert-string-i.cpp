class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int infinity = INT_MAX;
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));

        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] < infinity && dist[k][j] < infinity) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long total_cost = 0;
        int n = source.length();

        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (dist[u][v] >= infinity) {
                return -1;
            }
            
            total_cost += dist[u][v];
        }

        return total_cost;
    }
};