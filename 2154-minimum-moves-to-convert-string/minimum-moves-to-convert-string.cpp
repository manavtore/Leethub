class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        int n = s.size();
        int i = 0;
        
        while(i<n){
            if(s[i]=='X'){
                s[i]='0';
                moves++;
                i+=3;
            }else{
                i++;
            }
        }
        return moves;
    }
};