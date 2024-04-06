class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    s[i]='*';
                }
            }
        }
        while(!st.empty()){
            s[st.top()]='*';
            st.pop();
        }
        string result;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*') result.push_back(s[i]);
        }
        return result;
    }
};