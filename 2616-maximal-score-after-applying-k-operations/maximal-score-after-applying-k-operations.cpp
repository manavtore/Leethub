class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        while(k-- > 0){
            int curr = pq.top();
            pq.pop();
            score += curr;
            pq.push(ceil(curr/3.0));
        }
        return score;
    }
};