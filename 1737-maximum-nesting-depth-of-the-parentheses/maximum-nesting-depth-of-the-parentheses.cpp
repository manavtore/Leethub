class Solution {
public:
    int maxDepth(string s) {
        int maximum =0;
        int depth =0;
        for(char c : s){
            if(c=='('){
                depth++;
                maximum = max(depth,maximum);
            }else if(c == ')'){
                depth--;
            }
        }
        return maximum;
    }
};