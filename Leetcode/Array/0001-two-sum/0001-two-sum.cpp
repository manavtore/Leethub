class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n=nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int remain = target - a;
            if (map.find(remain) != map.end()) {
                return {map[remain], i};
            }
            map[a] = i;
        }

        return {}; 
    }
};
