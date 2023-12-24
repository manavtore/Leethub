class Solution {
public:

    int binarysearch(vector<int> arr,int low ,int high,int target){
        // if (arr.size()==1 && arr[0]==target) return 0;
        while(low<=high){
            int mid =(low+high)/2;
            if(arr[mid]==target){
                return mid;
            }else if(target<arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;

    }
    int search(vector<int>& nums, int target) {
       int  ans = binarysearch(nums,0,nums.size()-1,target);
        return ans;
    }
};