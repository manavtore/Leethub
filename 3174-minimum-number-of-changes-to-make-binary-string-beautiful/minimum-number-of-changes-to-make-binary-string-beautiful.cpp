class Solution {
public:
    int minChanges(string s) {
        int l = 0;
        int cnt = 0;

        for(int r=0;r<s.length();r++){
            if(s[r] != s[l]){
                if(r & 1){
                    cnt++;
                }
                l = r;
            }
        }

        return cnt;
    }
};