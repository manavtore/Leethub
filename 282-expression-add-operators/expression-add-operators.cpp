class Solution {
public:
    void solve(int i,string s,long sum,long prev,string& nums,vector<string>& ans,int target ){
        if(i==nums.size()){
            if(sum==target){
                 ans.push_back(s);
                 return;
            }
        }
         for(int j=i;j<nums.size();j++){
             if(j>i && nums[i]=='0') return;

             string currentStr = nums.substr(i, j - i + 1);
             long number = stol(currentStr);
             if(i==0){
                 solve(j+1,s+currentStr,number,number,nums,ans,target);
             }else{
                 solve(j+1,s+'+'+currentStr,sum+number,number,nums,ans,target);
                 solve(j+1,s+'-'+currentStr,sum-number,-number,nums,ans,target);
                 solve(j+1,s+'*'+currentStr,(sum-prev)+(number*prev),prev*number,nums,ans,target);

             }
         }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0,"",0,0,num,ans,target);
        return ans;
    }
};