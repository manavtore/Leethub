class Solution {
private:
    void dfs(int row,int col,int initialColor,vector<vector<int>>& ans,vector<vector<int>>& image,int color,vector<int>& delrow,vector<int>& delCol){  
            ans[row][col]=color;
            int n = image.size();
            int m = image[0].size();

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delCol[i];
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=color){
                    dfs(nrow,ncol,initialColor,ans,image,color,delrow,delCol);
                }
            }

    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delCol = {0,+1,0,-1};
        dfs(sr,sc,initialColor,ans,image,color,delrow,delCol);
        return ans;

    }
};