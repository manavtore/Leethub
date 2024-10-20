class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch:expression){
            
            if(ch == ',') continue;

            if(ch != ')'){
                st.push(ch);
            }else{
                vector<int> val;
                while(st.top() != '('){
                    val.push_back(st.top() == 't');
                    st.pop();

                }
                st.pop();

                char op = st.top();
                st.pop();
                bool res;

                if(op == '!'){
                    res = !val[0];
                }else if( op == '&'){
                    res = true;
                    for(auto va:val) res &=va;
                }else{
                    res = false;
                    for(auto va:val) res |=va;
                }

                st.push( res ? 't': 'f');

            }
        }
        return st.top() == 't';
    }
};