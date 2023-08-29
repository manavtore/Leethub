class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> final;
        
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=final[i-1][j]+final[i-1][j-1];
            }
            final.push_back(row);
        }
        return final;
    }
};