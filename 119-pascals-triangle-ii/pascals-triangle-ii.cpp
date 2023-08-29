class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int res;
        for(int i=0;i<=rowIndex;i++){
            
        res=returnelement(rowIndex,i);
        
        ans.push_back(res);
        }
        return ans;
    }

    int returnelement(int row,int column){
     long long res=1;
     for(int i=0;i<column;i++){
       res = res * (row-i);
       res = res / (i+1);
       
     }
     return res;
    }
};