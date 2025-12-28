class Solution {
public:
    int firstNonNegative(vector<int>& nums){
        int low = 0,high = nums.size();
        while(low<high){
            int mid = low + (high - low)/2;
            if(nums[mid]<0){
                low = mid +1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    int firstPositive(vector<int>& nums){
        int low = 0,high = nums.size();
        while(low<high){
            int mid = low + (high - low)/2;
            if(nums[mid]<=0){
                low = mid +1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int neg = firstNonNegative(nums);
        int pos = n - firstPositive(nums);

        return max(neg,pos);
        
    }
};