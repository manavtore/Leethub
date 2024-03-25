class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int num:nums){
            if(mp.find(num)!=mp.end()) ans.push_back(num);
            else mp[num]++;
        }
        return ans;
    }
};