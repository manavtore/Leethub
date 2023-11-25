class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixsum(n),suffixsum(n);
        
        prefixsum[0]=0;
        for(int i=1;i<n;i++){
           prefixsum[i]=prefixsum[i-1]+(i*(nums[i]-nums[i-1]));
        }
        suffixsum[n-1]=0;
        for(int i=n-2;i>=0;i--){
            suffixsum[i]=suffixsum[i+1]+((n-1-i)*(nums[i+1]-nums[i]));
        }
           vector<int> ans(n); 
        for(int i=0;i<n;i++){
         ans[i]=prefixsum[i]+suffixsum[i];
        }
      
        return ans;

    }
};