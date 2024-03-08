class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        int frequency=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int current=nums[i];
            freq[current]++;
            maxi=max(maxi,freq[current]);
        } 
        for(int i=0;i<freq.size();i++){
            if(freq[i]==maxi){
                frequency +=maxi;
            }
        }
        return frequency;
    }
};