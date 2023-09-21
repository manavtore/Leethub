class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mapin;
        for(int num:nums){
            if(mapin.count(num)>0){
                return true;
            }
            mapin.insert(num);
        }
        return false;
    }
};