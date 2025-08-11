class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
             int curr = nums[i];
             int rm = target - curr;
             if(mp.find(rm) != mp.end()){
                return {mp[rm],i};
             }
             mp[curr]=i;
        }
        return {-1,-1};
    }
};