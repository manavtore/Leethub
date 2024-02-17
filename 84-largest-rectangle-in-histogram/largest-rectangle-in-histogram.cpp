class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
         stack<int> st;
         int maxArea = 0;
    
    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int l = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, l * w);
        }
        st.push(i);
    }
    
    return maxArea;
    }
};