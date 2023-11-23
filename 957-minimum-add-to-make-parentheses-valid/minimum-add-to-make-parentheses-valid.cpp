class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt=0;
        for(auto a:s){
            if(a =='('){
                st.push(a);
            }else if(a==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    cnt++;
                }
            }

        }
        return cnt+st.size();
    }
};