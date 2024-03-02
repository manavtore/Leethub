class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int left,right;
        left =0;
        right = n-1;
        int idx=n-1;
        while(left<=right){
            int sq1=nums[left]*nums[left];
            int sq2=nums[right]*nums[right];
            if(sq1>sq2){
                ans[idx--]=sq1;
                left++;
            }else{
                ans[idx--]=sq2;
                right--;
            }


        }
        return ans;
        
    }

};
