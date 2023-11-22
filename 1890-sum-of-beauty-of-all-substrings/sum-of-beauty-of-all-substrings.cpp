class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char,int> map;
            for (int j = i; j < s.length(); j++) {
                map[s[j]]++;
                int maxcount=0,mincount=INT_MAX;
                 for(auto it: map){
                      maxcount = max(maxcount,it.second);
                      mincount = min(mincount,it.second);
            }
              res += maxcount - mincount;
            }
           

           
        }
        return res;
    }
};
