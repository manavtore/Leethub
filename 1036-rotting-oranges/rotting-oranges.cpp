class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        int visited[n][m];
        queue<pair<pair<int,int>,int>> q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i,j},0});
                    
                }else{
                    visited[i][j]=0;
                }

                if(grid[i][j]==1) count++;
            }
        }

        int drow[]={-1,0,1,0};
        int dclo[]={0,1,0,-1};
        int tm =0;
        int cnt=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dclo[i];

                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                    visited[nrow][ncol]=2;
                }
            }
        }
        if(count!=cnt) return -1;

     return tm;
    }
};