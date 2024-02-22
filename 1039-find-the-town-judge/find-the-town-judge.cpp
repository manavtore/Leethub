class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()<n-1) return -1;
        if(n==1) return 1;

        unordered_map<int,int> trusties;
        unordered_map<int,bool> booling;

        for(const auto& relation:trust){
            trusties[relation[1]]++;
            booling[relation[0]]=true;
        }

        for(int i=0;i<=n;i++){
            if(trusties[i]==n-1 && booling[i]!=true) return i;
        }
        return -1;
    }
};