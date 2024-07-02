class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int it:nums1){
            mp[it]++;
        }

        for(int num:nums2){
            if(mp[num]>0){
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};