class Solution {
public:
    bool check(vector<vector<char>>& board,string& word,int i,int j,int index){
        if (index == word.length()) {
            return true;
            }
            int m=board.size();
            int n=board[0].size();


            if(i<0 || i>=m || j<0 || j>=n || word[index]!=board[i][j]){
                return false;
            }
             char temp=board[i][j];
             board[i][j]='#';

      
              bool found =  check(board, word, i + 1, j, index + 1) ||
                check(board, word, i, j + 1, index + 1) ||
                check(board, word, i, j - 1, index + 1) ||
                check(board, word, i - 1, j, index + 1);
       
                
                board[i][j]=temp;

            return found;
            }
            
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};