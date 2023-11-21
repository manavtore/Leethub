class Solution {
public:
   
    int beautySum(string s) {
        int res = 0;
        for(int i=0;i<s.length();i++){
              vector<int>map(26,0);
            for(int j=i;j<s.length();j++){
                  map[s[j]-'a']++;
                  res = res + beauty(map);

            }
        }

        return res;
    }
     int beauty(vector<int> map){
        int maxf=-1;
        int lowf = 1e9;
       for(int i=0;i<26;i++){
           maxf = max(maxf,map[i]);
           if(map[i]>=1){
               lowf = min(lowf,map[i]);
           }
       }
       return maxf-lowf;
    }
};