class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;

        for(auto num:nums){
            totalSum+=num;
        }
        int target_Mod = totalSum % p;
        if(target_Mod == 0){
            return 0;
        }

        unordered_map<int,int> prefixMap;
        prefixMap[0] = -1;

        long long prefixSum = 0;
        int minLength = n;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            int current_mod = prefixSum % p;

            int req_mod = ((current_mod - target_Mod + p ) % p);

            if( prefixMap.find(req_mod) != prefixMap.end()){
                minLength = min( minLength , i - prefixMap[req_mod]);
            }   

            prefixMap[current_mod] = i; 
        }

          return (minLength == n) ? -1 : minLength;
    }
};