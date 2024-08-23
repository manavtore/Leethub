class DisjointSet{
    public:
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=findParent(parent[n]);
    }

    void union_g(int a,int b){
        int parent_a = parent[a];
        int parent_b = parent[b];
        if(parent_a==parent_b) return ;
        if(parent_a<parent_b){
             parent[parent_a] = parent_b;
             size[parent_b]+=size[parent_a];
        }else{
            parent[parent_b] = parent_a;
            size[parent_a]+=size[parent_b];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        if(edge.size()< n-1) return -1;
        DisjointSet s(n);

        int cntExtra =0;
        for(auto it:edge){
            int u = it[0];
            int v = it[1];
            if(s.findParent(u)==s.findParent(v)){
                cntExtra++;
            }else{
                s.union_g(u,v);
            }   
        }
        int cnt =0;

        for(int i=0;i<n;i++){
            if(s.findParent(i)==i){
                cnt++;
            }
        }
        int ans = cnt-1;
        
        if(cntExtra>=ans){
            return ans;
        }
        return -1;

     }
};