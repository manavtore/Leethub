class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int r=0,l=0;
        int n=s.length();
        int maxlength=0;
        while(r<n){
            if(mpp[s[r]] != -1){
                l=max(mpp[s[r]]+1,l);
            }
            mpp[s[r]]=r;
            maxlength=max(maxlength,r-l+1);
            r++;
        }
        return maxlength;

    }
};