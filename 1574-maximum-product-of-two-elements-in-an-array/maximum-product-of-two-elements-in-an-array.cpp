class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(((nums[i]-1)*(nums[j]-1))>product) {
                      product=((nums[i]-1)*(nums[j]-1));
                }
              
            }
        }
        return product;
    }
};