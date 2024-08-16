class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;

        int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        vector<vector<int>> visited(n,vector<int> (m,false));

        visited[0][0]=true;
        queue<pair<int,int>> q;
        int ans = 1; 
        q.push({0,0});

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int x = q.front().first;
               int y = q.front().second;
                q.pop();
                if(x == n-1 && y == m-1) return ans;
               for(int j=0;j<8;j++){
                  int newX = x + dir[j][0];
                  int newY = y + dir[j][1];
  
                 if(newX>=0 && newX<=n-1 && newY>=0 && newY<=m-1 && visited[newX][newY]==false && grid[newX][newY]==0){
                     q.push({newX,newY});
                    visited[newX][newY] = true;
                }
            }
           
            }
             ans++;
           
        }
        return -1;
     }
};