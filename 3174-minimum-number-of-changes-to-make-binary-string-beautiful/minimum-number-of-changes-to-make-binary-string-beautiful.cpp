class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        for(int r=0;r<s.length()-1;r+=2){
            if(s[r] != s[r+1]){
                cnt++;
            }
        }

        return cnt;
    }
};