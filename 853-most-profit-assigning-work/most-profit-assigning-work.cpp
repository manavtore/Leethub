class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int n = difficulty.size();
        for(int i=0;i<n;i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int maxProfit = 0,currentProfit = 0,i=0;
        for(auto w:worker){
            while(i<n && w>=jobs[i].first){
                currentProfit = max(currentProfit,jobs[i].second);
                i++;
            }
            maxProfit+=currentProfit;
        }
        return maxProfit;
    }
};