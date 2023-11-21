class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int pairs=0;
        const int MOD = 1e9+7;
        unordered_map<int ,int > freq;
        for(auto el:nums){
            int val = el - rev(el);
            pairs=(pairs+freq[val])%MOD;
            freq[val]++;
        }
        return pairs;
    }

    int rev(int n){
        long long int reverse =0;
    
       while(n>0){
         reverse= reverse * 10+ n%10 ;
         n = n/10;
       }
       return reverse;
    }
};