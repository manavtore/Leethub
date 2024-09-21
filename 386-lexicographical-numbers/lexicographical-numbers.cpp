class Solution {
    void dfs(int curr,int n,vector<int>& lexo){
        if(curr>n) return;

        lexo.push_back(curr);

        for(int i=0;i<10;i++){
            int next = curr * 10 +i;
            if(next > n) return;
            dfs(next,n,lexo);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexo;

        for(int i=1;i<=9;i++){
            if(i>n) break;

            dfs(i,n,lexo);
        }
        return lexo; 
    }
};