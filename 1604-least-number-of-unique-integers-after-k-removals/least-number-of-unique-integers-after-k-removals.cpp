class Solution {
public:

     struct compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;
        }
    };
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int min=-1;
        unordered_map<int,int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for(auto num: arr){
           freq[num]++;
        }

        for(auto fre : freq){
            pq.push(fre);
        }
        while(k>0 && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(top.second<=k){
                k-=top.second;
            }else{
                pq.push({top.first,top.second-k});
                k=0;
            }
        }

        return pq.size();
    }
};