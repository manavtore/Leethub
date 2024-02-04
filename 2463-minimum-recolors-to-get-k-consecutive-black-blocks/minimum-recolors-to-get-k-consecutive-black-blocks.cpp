class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mini=INT_MAX;
        int change=0;
        for(int i=0;i<blocks.size();i++){
            if(blocks[i]=='W') change++;
            if(i<k-1) continue;
            mini=min(mini,change);
            if(blocks[i-(k-1)]=='W') change--;
        }
        return mini;
    }
};