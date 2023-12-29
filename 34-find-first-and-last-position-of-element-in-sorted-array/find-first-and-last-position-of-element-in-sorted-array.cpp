class Solution {
public:
  int firstoccurence(vector<int>& nums,int target){
      int low=0,high=nums.size()-1;
      int first=-1;
      while(low<=high){
          int mid=(low+high)/2;
          if(nums[mid]==target){
              first=mid;
              high=mid-1;
          }else if(target>nums[mid]){
              low=mid+1;
          }else{
              high=mid-1;
          }
      }
      return first;

  }
  int lastoccurence(vector<int>& nums,int target){
      int low=0,high=nums.size()-1;
      int last=-1;
      while(low<=high){
          int mid=(low+high)/2;
          if(nums[mid]==target){
              last=mid;
              low=low+1;
          }else if(target>nums[mid]){
               low=mid+1;
          }else{
              high=mid-1;
          }
      }
      return last;

  }

    vector<int> searchRange(vector<int>& nums, int target) {
       int first=firstoccurence(nums,target);
       if(first==-1) return {-1,-1};
       int last=lastoccurence(nums,target);
       return {first,last};
    }
};