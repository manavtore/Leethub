class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> group;
        for(const auto& str:strs){
            vector<int> freq(26,0);
            string hashStr="";
            for(auto s:str) freq[s-'a']++;
            for(int i=0;i<26;i++){
                hashStr.push_back(freq[i]);
                hashStr.push_back('#');
            }
           group[hashStr].push_back(str);
        }
        vector<vector<string>> anagrams;
        for(const auto& pair :group){
            anagrams.push_back(pair.second);
        }   
        return anagrams;
       
    }
};