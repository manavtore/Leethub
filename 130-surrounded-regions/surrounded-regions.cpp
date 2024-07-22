class Solution {
private:
    void dfs(int row,int col,int delRow[],int delCol[],vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n = board.size();
        int m = board[0].size();
        

        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow<n && nCol<m && nRow>=0 && nCol>=0 && vis[nRow][nCol]==0 && board[nRow][nCol]=='O'){
                dfs(nRow,nCol,delRow,delCol,vis,board);
                
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] ={-1,0,1,0};
        int delCol[] ={0,-1,0,1};
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i] == 'O'){
              dfs(0,i,delRow,delCol,vis,board);
            }

            if(vis[n-1][i]==0 && board[n-1][i]=='O'){
                dfs(n-1,i,delRow,delCol,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0] == 'O'){
               dfs(i,0,delRow,delCol,vis,board);
            }

            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,delRow,delCol,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0  && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};