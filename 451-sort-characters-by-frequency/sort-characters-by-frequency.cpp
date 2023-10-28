class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int> frequency;


        for(int i=0;i<n;i++){
            if(frequency.find(s[i])!=frequency.end()){
                frequency[s[i]]++;
            }else {
                frequency[s[i]]=1;
            }
        }
        
        vector<pair<char,int>> freqVector(frequency.begin(),frequency.end());
        
        sort(freqVector.begin(),freqVector.end(),[](const auto& a,const auto& b){
            return a.second>b.second;
        });

        string result;

        for(const auto& pair: freqVector){
            result += string(pair.second,pair.first);
        }
        
        return result;

        
        
    }
};