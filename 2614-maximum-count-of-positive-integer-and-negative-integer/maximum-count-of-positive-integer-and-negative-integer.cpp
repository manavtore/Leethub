class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
    
        int pos = 0;
        int neg = 0;
        for(int i=0;i<n;i++){
            int curr = nums[i];
            if(curr > 0){
                pos++;
            }else if(curr < 0){
                neg++;
            }
        }
        return max(pos,neg);
    }
};