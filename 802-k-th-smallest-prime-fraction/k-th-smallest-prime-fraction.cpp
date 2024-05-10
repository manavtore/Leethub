class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0; 
        
        while(left < right) {
            double mid = left + (right - left) / 2;
            int count = 0;
            double maxFraction = 0.0;
            vector<int> res = {0, 0};
            
            for(int i = 0, j = 1; i < n - 1; i++) {
                while(j < n && arr[i] >= arr[j] * mid) j++;
                count += n - j;
                if(j < n && maxFraction < (double)arr[i] / arr[j]) {
                    maxFraction = (double)arr[i] / arr[j];
                    res = {arr[i], arr[j]};
                }
            }
            
            if(count == k) return res;
            else if(count < k) left = mid;
            else right = mid;
        }
        
        return {};
    }
};
