class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
        int n=nums.size();
        unordered_map<int,int> mp(n);
        for(int i=1;i<=n;i++){
            mp[i]=0;
        }
        for(int num:nums){
            mp[num]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0) return i;
        }
        return  n+1;
       
    }
};