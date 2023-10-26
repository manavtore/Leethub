class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int Rows = board.size();
       int column = board[0].size();

       for(int i=0;i<Rows;i++){
           for(int j=0;j<column;j++){
               if(searchword(board,word,i,j,0)){
                   return true;     
               }
           }
       }
          return false;
        
    }
    bool searchword(vector<vector<char>>& board, string word,int i,int j,int index){
           if(index == word.length()){
                   return true;
               }
          if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!= word[index]){
                   return false ;
               }

        char currentchar = board[i][j];
        board[i][j] = ' '; 

        bool found = searchword(board,word,i-1,j,index+1) ||
                     searchword(board,word,i+1,j,index+1) ||
                     searchword(board,word,i,j+1,index+1) ||
                     searchword(board,word,i,j-1,index+1) ;

        board[i][j] = currentchar;

        return found;        
    
    }
};