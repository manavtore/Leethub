class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> matrixcopy = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> prevHeight;
        int ans = 0;
        for(int row=0;row<m;row++){

            vector<pair<int,int>> heights;
            vector<bool> seen(n,false);

            for(auto [h,col] : prevHeight){
                if(matrix[row][col]){
                    heights.push_back({h+1,col});
                    seen[col] = true;
                }
            }

            for(int col=0;col<n;col++){
                if(seen[col]==false && matrix[row][col]){
                    heights.push_back({1,col});
                }
             

            }
            for(int i=0;i<heights.size();i++){
                ans=max(ans,heights[i].first*(i+1));
            }
               prevHeight=heights;


        }
        return ans;
    }
};