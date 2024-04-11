class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(auto c:num){
            while(!st.empty() && st.top()>c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }   

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        int endingindex = 0;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]!='0'){
                endingindex=i;
                break;
            }
        }
        ans = ans.substr(0,endingindex+1);

        reverse(ans.begin(),ans.end());
        if(ans=="") return "0";
        return ans;

        }
};