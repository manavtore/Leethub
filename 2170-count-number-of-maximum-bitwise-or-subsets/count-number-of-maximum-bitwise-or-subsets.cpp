class Solution {
    void backTrack(int ind,int maxOR,int currentOR,vector<int>& nums,int& cnt){
        if(ind == nums.size()){
            if(maxOR == currentOR){
                cnt++;
            }
            return;
        }
        backTrack(ind+1,maxOR,currentOR | nums[ind],nums,cnt);

        backTrack(ind+1,maxOR,currentOR ,nums,cnt);


    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxOR = 0;  
        for(int num:nums ){
            maxOR |= num;
        }
        int cnt = 0;
         backTrack(0,maxOR,0,nums,cnt);
        return cnt;
    }   
};