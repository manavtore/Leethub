class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt ){
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        for(auto& edge:edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
                     dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        int cityno = -1;
        int citycnt = n;

        for(int city=0;city<n;city++){
            int cnt =0;
            for(int adj=0;adj<n;adj++){
                if(dist[city][adj]<=dt) cnt++;
            }
            if(cnt<=citycnt){
                citycnt = cnt;
                cityno = city;
            }

        }
        return cityno;

    }
};