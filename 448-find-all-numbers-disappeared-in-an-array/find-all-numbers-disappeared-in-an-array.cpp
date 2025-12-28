class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(nums[nums[i]-1] != nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }

};