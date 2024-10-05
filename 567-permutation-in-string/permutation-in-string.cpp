class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }

        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        for(int i=0;i<s1.length();i++){
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

         if(s1map == s2map) return true;
        
        int end = s1.length();
        int start = 0;
        while(end < s2.length() ){
            
            s2map[s2[end]-'a']++;
            s2map[s2[start]-'a']--;

            if(s1map==s2map) return true;

            start++;
            end++;
        }
        return false;
    }
};