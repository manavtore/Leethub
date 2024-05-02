class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,bool> mp; 
        for(auto num:nums){
            if(num>0) mp[num]=true;
        }
        int maxi = INT_MIN;
        for(auto num:nums){
            if(num<0){
                if(mp.find(-num)!=mp.end()) maxi = max(maxi,-num); 
            }
        }
        if(maxi!=INT_MIN) return maxi;
        else return -1;
    }
};