class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n= names.size();
        unordered_map<int,string> mp(n);
        

        for(int i=0;i<n;i++){
            mp[heights[i]]= names[i];
        }

        sort(heights.begin(),heights.end(),greater<int>());
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=mp[heights[i]];
        }
        return ans;
    }
};