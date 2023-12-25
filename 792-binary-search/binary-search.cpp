class Solution {
public:

    int binarysearch(vector<int> arr,int low ,int high,int target){
        while(low<=high){
            int mid =(low+high)/2;
            if(arr[mid]==target){
                return mid;
            }else if(target<arr[mid]){
                return binarysearch(arr,low,mid-1,target);
            }else{
              return  binarysearch(arr,mid+1,high,target);
            }
        }
        return -1;

    }
    int search(vector<int>& nums, int target) {
       int  ans = binarysearch(nums,0,nums.size()-1,target);
        return ans;
    }
};