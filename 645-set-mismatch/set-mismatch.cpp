class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int missing=0;
        int duplicate=0;
        vector<int> freq(n+1,0);


        for(int i=0;i<n;i++){
            freq[nums[i]]++;
                }
        for(int i=1;i<freq.size();i++){
            if(freq[i]==2) duplicate=i;
            if(freq[i]==0) missing=i;
        }
        return {duplicate,missing};
        
    }
};