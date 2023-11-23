class Solution {
public:
    bool check(vector<int>& arr){
         int maxelement= INT_MIN;
         int minelement = INT_MAX;
         int n = arr.size();
         unordered_set<int> element;

        for(auto value: arr){
            maxelement = max(maxelement,value);
            minelement = min(minelement,value);
            element.insert(value);
        } 
          
          

          if((maxelement-minelement)%(n-1)!=0) return false;
          int diff = (maxelement - minelement)/(n-1) ;
          int current = minelement + diff;

          while(current<maxelement){
              if(element.find(current)==element.end()) return false;
              current+=diff;
          }
          return true;
        
        
    }


    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
          for(int i=0;i<l.size();i++){
               vector<int> arr(begin(nums)+l[i],begin(nums)+r[i]+1);
               ans.push_back(check(arr));

          }
          return ans;
    }
};