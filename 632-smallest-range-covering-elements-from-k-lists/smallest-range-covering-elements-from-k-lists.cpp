class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        int currentMax = INT_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }
        
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while (true) {
            auto [currentMin, row, index] = minHeap.top();
            minHeap.pop();
            
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
            if (index + 1 == nums[row].size()) {
                break;
            }
            
            int nextVal = nums[row][index + 1];
            minHeap.push({nextVal, row, index + 1});
            currentMax = max(currentMax, nextVal);
        }
        
        return {rangeStart, rangeEnd};
    }
};