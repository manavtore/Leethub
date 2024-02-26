class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        stack<int> st;
        
        for(int i=0;i<n;i++){   
            if(st.empty() || ast[i]>0){
                st.push(ast[i]);
            }else{
                while(!st.empty() && st.top()<abs(ast[i]) && st.top()>0 ){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(ast[i])){
                    st.pop();
                }else{
                    if(st.empty() || st.top()<0){
                        st.push(ast[i]);
                    }
                }
            }
        }
        vector<int> result(st.size());
        for(int i=(int)st.size()-1;i>=0;i--){
            result[i]=st.top();
            st.pop();

        }
        return result;
    }
};