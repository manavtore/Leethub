class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char ,int > map;
        
        if(s.length()!=t.length()){
            return false;
        }

        for(char ch: s){
           map[ch]++;
        }

        for(char c: t){
            if(map.find(c)==map.end()  || map[c]==0){
                return false;
            }
            map[c]--;
        }
        return true;
    }
};