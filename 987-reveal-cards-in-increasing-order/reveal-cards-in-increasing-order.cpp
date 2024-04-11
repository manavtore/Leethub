class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n=deck.size();
        for(int i=0;i<n;i++){
            q.push(i);
        }
        sort(deck.begin(),deck.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[q.front()]=deck[i];
            q.pop();
             if(!q.empty()){
                q.push(q.front());
                q.pop();
             }
        }
        return ans;
    }
};