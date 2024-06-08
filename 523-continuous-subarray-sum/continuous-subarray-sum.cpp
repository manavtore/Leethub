class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int currentSum=0;
        mp[0]=0;
        for(int i=0;i<nums.size();i++){
            currentSum=(currentSum+nums[i])%k;
            if(mp.find(currentSum)!=mp.end()){
                if(i+1-mp[currentSum]>=2){
                    return true;
                }
            }else{
                mp[currentSum]=i+1;
            }
        }
        return false;  
    }
};