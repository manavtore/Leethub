class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
          ans.push_back(1); 
        long long res=1;
        for(int i=1;i<=rowIndex;i++){
          res = res *(rowIndex-i+1);
          res = res / i;
          ans.push_back(res);
        }
         
        return ans;
    }


};