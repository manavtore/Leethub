class DisjointSet{
    public:
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void union_g(int a,int b){
        int parent_a = findParent(a);
        int parent_b = findParent(b);
        if(parent_a==parent_b) return ;
        if(size[parent_a]<size[parent_b]){
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
    int removeStones(vector<vector<int>>& stones) {
      int maxRow = 0;
      int maxCol = 0;
      for(auto it:stones){
        maxRow = max(maxRow,it[0]);
        maxCol = max(maxCol,it[1]);
      }
      
      DisjointSet ds(maxRow + maxCol + 1);
      unordered_map<int,int> mp;

      for(auto it:stones){
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow +1;
        ds.union_g(nodeRow,nodeCol);
        mp[nodeRow]=1;
        mp[nodeCol]=1;
       }
      int cnt =0;
      for(auto it:mp){
        if(ds.findParent(it.first)==it.first){
            cnt++;
        }
      }
      return stones.size() - cnt;
    }
};