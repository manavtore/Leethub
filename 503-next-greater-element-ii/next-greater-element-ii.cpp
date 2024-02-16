class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,-1);
        stack<int> st;

        for(int i=0;i<n*2;i++){
            int num=nums[i%n];
            while(!st.empty() && nums[st.top()]<num){
                result[st.top()]=num;
                st.pop();
            }
            if(i<n) st.push(i);
        }
        return result;
    }
};