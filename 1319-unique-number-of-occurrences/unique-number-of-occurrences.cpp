class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        unordered_set<int> occurences;
        for(const auto& entry:freq){
            if(occurences.find(entry.second)!=occurences.end()){
                return false;
            }
            occurences.insert(entry.second);
            }
        
        return true;
    }
};