class Solution {
public:
    void solveQueens(int n,int col,vector<vector<string>>& ans,vector<int>& left,vector<int>& upperleft,vector<int>& lowerleft,vector<string>& board) {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && upperleft[row+col]==0 && lowerleft[n-1+col-row]==0 ){
                board[row][col]='Q';
                left[row]=1;
                upperleft[row+col]=1;
                lowerleft[n-1+col-row]=1;
                solveQueens(n,col+1,ans,left,upperleft,lowerleft,board);
                board[row][col]='.';
                left[row]=0;
                upperleft[row+col]=0;
                lowerleft[n-1+col-row]=0;

            }
        }
    }
  
  
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> left(n,0),upperleft(2*n-1,0),lowerleft(2*n,0);

        solveQueens(n,0,ans,left,upperleft,lowerleft,board);
        return ans;
        
        }
    
};