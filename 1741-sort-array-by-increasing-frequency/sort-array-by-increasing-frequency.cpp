class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto num:nums){
            mp[num]++;
        }

        vector<pair<int,int>> freq(mp.begin(),mp.end());

        sort(freq.begin(),freq.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.second==b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        vector<int> result;
        for(const auto& p:freq){
            result.insert(result.end(),p.second,p.first);
        }
        return result;
    }
};