class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int,int>> arrival;

        for(int i=0;i<n;i++){
            arrival.push_back({times[i][0],i});
            arrival.push_back({times[i][1],~i});
        }
        
        sort(arrival.begin(),arrival.end());

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<n;i++){
            pq.push(i);
        }

        vector<int> availChair(n,-1);

        for(auto& [a,b]:arrival){
            if(b>=0){
                int chair = pq.top();
                pq.pop();
                availChair[b] = chair;

                if(b==targetFriend){
                    return chair;
                }
            }else{
                b = ~b;
                pq.push(availChair[b]);
            }
        }

        return -1;

    }
};