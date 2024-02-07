class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto ch:s){
            freq[ch]++;
        }
        vector<vector<int>> DataBucket(s.length()+1);
        for(auto [c,fq]: freq) DataBucket[fq].push_back(c);
        string ans;
        for(int i=s.length();i>0;i--){
            for(auto c:DataBucket[i]){
                ans.append(i,c);
            }
        }
        return ans;
    }
};