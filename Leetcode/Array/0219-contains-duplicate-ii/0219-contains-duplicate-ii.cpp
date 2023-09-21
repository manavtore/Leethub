class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int> mapi;
        
        for(int i=0;i<nums.size();i++){
            
           if(mapi.count(nums[i])>0){
               if(i-mapi[nums[i]]<=k){
                   return true;
               }else
                   mapi[nums[i]]=i;
           }else
               mapi.insert({nums[i],i});
        }
        return false;
    }
};
