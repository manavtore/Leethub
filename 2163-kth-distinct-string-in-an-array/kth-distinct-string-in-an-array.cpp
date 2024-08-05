class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;

        for(auto it:arr){
            mp[it]++;
        }
        vector<string>v;
        for(auto it:arr){
            if(mp.find(it)!=mp.end()&& mp[it]==1){
v.push_back(it);
            }
        }
        for(auto it:v)cout<<it<<" ";
        if(v.size()>=1 && k-1<v.size())
        return v[k-1];
        else 
        return "";
    }
};