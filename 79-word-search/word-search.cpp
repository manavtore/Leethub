class Solution {
public:
    bool check(vector<vector<char>>& board,int i,int j,int index,string word){
        if(index==word.length()){
            return true;
        }
        int n=board.size();
        int m=board[0].size();

        if(i<0 || i>=n || j<0 || j>=m || word[index]!=board[i][j]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';

        bool found = check(board,i+1,j,index+1,word) ||
                     check(board,i,j+1,index+1,word) ||
                     check(board,i,j-1,index+1,word) ||
                     check(board,i-1,j,index+1,word) ;

         board[i][j]=temp;
         return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};