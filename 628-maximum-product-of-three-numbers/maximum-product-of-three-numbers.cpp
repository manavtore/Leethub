class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int product = nums[n-1]* nums[n-2] * nums[n-3]; 
         int product2 = nums[0] * nums[1] * nums[n-1];
        product =max(product,product2);
        return product;
    }
};