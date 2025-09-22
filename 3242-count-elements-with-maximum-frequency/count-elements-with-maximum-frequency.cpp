class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            freq[curr]++;
            maxi = max(freq[curr],maxi);
        }
        
        int final = 0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==maxi){
                final += freq[i];
            }
        }

        return final;
    }
};