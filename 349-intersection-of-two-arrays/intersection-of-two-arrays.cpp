class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> arr;
        set<int> s;
        for(int num:nums1){
            s.insert(num);
        }
        for(int num : nums2){
            if(s.find(num)!=s.end()){
                arr.insert(num);
            }
        }
        
        vector<int> ans;
        for(int num:arr){
            ans.push_back(num);
        }
        return ans;
    }
};