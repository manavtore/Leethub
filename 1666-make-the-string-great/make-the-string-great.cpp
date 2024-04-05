class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(!st.empty() && (st.top()==toupper(c)  || st.top() ==tolower(c)) && st.top()!=c){
                st.pop();
            }else{
                 st.push(s[i]);
            }
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};