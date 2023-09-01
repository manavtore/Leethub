class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int maxVal = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < maxVal) {
                maxVal = nums[i];
                count++;
            }

            if (count == 3) {
                return maxVal;
            }
        }

        return nums[0]; 
}
};