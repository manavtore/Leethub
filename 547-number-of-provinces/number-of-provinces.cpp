class Solution {
private:
    void dfs(int Node,vector<vector<int>>& isConnected,vector<bool>& visited){
        visited[Node]=true;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[Node][j]==1 && !visited[j]){
                dfs(j,isConnected,visited);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
    }
};