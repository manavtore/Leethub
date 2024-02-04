class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int whitecnt=0;
        
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                whitecnt++;
            }
        }
        int mini=whitecnt;
        for(int i=k;i<n;i++){
            if(blocks[i-k]=='W'){
                whitecnt--;
            }
            if(blocks[i]=='W'){
                whitecnt++;
            }
            mini=min(mini,whitecnt);
        }
     return mini;

    }
};