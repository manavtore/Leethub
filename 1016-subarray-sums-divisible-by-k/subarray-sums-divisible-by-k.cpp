class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt =0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            int mod = ((sum%k)+k)%k;
            if(mp.find(mod)!=mp.end()){
                cnt+=mp[mod];
            }
            mp[mod]++;
        }
        return cnt;
    }
};