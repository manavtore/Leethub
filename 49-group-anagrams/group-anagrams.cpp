class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> group;
        for(const auto& str:strs){
            string original=str;
            sort(original.begin(),original.end());
            group[original].push_back(str);
        }
        vector<vector<string>> anagrams;
        for(const auto& pair :group){
            anagrams.push_back(pair.second);
        }   
        return anagrams;
    }
};