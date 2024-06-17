class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge;

        for(const auto& interval:intervals){
            if(merge.empty() || interval[0]>merge.back()[1]){
                merge.push_back(interval);
            }else {
                merge.back()[1]=max(interval[1],merge.back()[1]);
            }
        }
        return merge;
    }
};