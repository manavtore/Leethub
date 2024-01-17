class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        unordered_set<int> occurences;
        for(auto entry:freq){
            occurences.insert(entry.second);
            }
        
        return occurences.size()==freq.size();
    }
};