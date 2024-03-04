class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int maxscore=0;
        int score=0;
        while(i<=j){
            if(tokens[i] <= power ){
                power-=tokens[i++];
                maxscore=max(++score,maxscore);  
            }else if(score>0){
                   power+=tokens[j--];
                   score--;
            }else {
                break;
            } 
        }
        return maxscore;
    }
};