class Solution {
public:
   unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string s) {
        
        if(memo.find(s)!=memo.end()){
            return memo[s];
        }
        
        vector<int> result;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='+' || c=='-' || c=='*'){

                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));


                for(auto l :left){
                    for(auto r:right){
                        if(c=='+'){
                             result.push_back(l + r);
                        }else if(c == '-'){
                             result.push_back(l - r);
                        }else{
                             result.push_back(l * r);
                        }
                    }
                }
            }

        }
        if(result.empty()){
            result.push_back(stoi(s));
        }
        memo[s] = result;
        return result;
    }
};