class Solution {
public:
    int hammingWeight(uint32_t n) {
        long long int ans=0;
        while(n){
            if(n%2){
                ans++;
            }
           n = n/2;
        }
        return ans;
    }
};