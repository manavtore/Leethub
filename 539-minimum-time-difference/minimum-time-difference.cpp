class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int n = timePoints.size();

        for(auto time:timePoints){
            int hourMin = stoi(time.substr(0,2));
            int remainMin = stoi(time.substr(3,2));
            minutes.push_back(hourMin * 60 + remainMin);
        }

        int minDiff = INT_MAX;

        sort(minutes.begin(), minutes.end());

        for(int i=1;i<n;i++){
            minDiff = min(minDiff, minutes[i]-minutes[i-1]);
         }
        
        int circularDiff = 1440 - (minutes.back()-minutes.front());
        minDiff = min(minDiff,circularDiff);

        return minDiff;
    }
};