class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        
        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        sort(workers.begin(), workers.end());
        
        double min_cost = numeric_limits<double>::infinity();
        priority_queue<int> quality_heap;
        int total_quality = 0;
        
        for (auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;
            quality_heap.push(q);
            total_quality += q;
            
            if (quality_heap.size() > k) {
                total_quality -= quality_heap.top();
                quality_heap.pop();
            }
            
            if (quality_heap.size() == k) {
                min_cost = min(min_cost, total_quality * ratio);
            }
        }
        
        return min_cost;
    }
};