class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> arr(cols,0);
        int maxArea=0;
        for(int j=0;j<cols;j++){
            arr[j]=matrix[0][j]-'0';
        }
         maxArea=largestRectangleArea(arr);

        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='0'){
                    arr[j]=0;
                }else{
                    arr[j]+=1;
                }
            }
            maxArea=max(maxArea,largestRectangleArea(arr));
        }
        return maxArea;
    }
     int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); 
        int n = heights.size();
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};