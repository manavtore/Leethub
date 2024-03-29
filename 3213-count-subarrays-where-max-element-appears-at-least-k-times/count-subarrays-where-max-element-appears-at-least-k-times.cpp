class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int j=0,i=0;
        long long cnt=0;
        unordered_map<int,int> mp;
        int maxi=0;
        for(auto el :nums) maxi=max(maxi,el);
        while(j<n){
            mp[nums[j]]++;
            while(mp[maxi]>=k){
                cnt+=n-j;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};