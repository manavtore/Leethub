class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++){
            if( result.empty() || intervals[i][0]>result.back()[1]){
                result.push_back(intervals[i]);
            }else{
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }
        }
        return result;
    }
};