class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n=nums.size();
      vector<int> result(n);
      int left=0;
      int right =n-1;
      int index=n-1;

      while(left<=right){
          int leftsquare = nums[left]*nums[left];
          int rightsquare =nums[right]*nums[right];

          if(leftsquare >=rightsquare){
              result[index]=leftsquare;
              left++;
          }else{
             result[index]=rightsquare;
             right--; 
          }
             
          index--;
      }
      return result;
    }
};