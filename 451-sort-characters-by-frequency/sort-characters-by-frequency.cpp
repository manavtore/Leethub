class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int> frequency;


        for(char c: s){
          frequency[c]++;        
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto pair: frequency){
            pq.push({pair.second,pair.first});
        }


        string result;
        pair<int,char> current;

        while(!pq.empty()){
            current=pq.top();
            pq.pop();
            result.append(current.first,current.second);
        }
        return result;

        
        
    }
};