class Solution {
public:

    void sortColors(vector<int>& nums) {
        int high = nums.size()-1;
        int low  = 0;
        int mid = 0;

        do{ 
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;

            }else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else{
                mid++;
            }
        }while(mid<=high);

    }
};