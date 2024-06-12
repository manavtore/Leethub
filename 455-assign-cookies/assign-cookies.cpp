class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int cnt =0;
        while(i<s.size() && j<g.size()){
            if(s[i]>=g[j]){
                cnt++;
                i++;
                j++;
            }else{
                i++;
            }
        }
        return cnt;
    }
};