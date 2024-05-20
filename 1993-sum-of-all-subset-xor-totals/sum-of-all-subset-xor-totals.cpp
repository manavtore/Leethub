class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalXorSum = 0;
        for (int i = 0; i < (1 << n); ++i) {  
            int currentXor = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentXor ^= nums[j];
                }
            }
            totalXorSum += currentXor;
        }
        
        return totalXorSum;
    }
};