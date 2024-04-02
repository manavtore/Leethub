class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mini=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<cards.size();i++){
            if(mp.find(cards[i])!=mp.end()){
                mini=min(mini,i-mp[cards[i]]+1);
                mp[cards[i]]=i;
            }else{
                mp[cards[i]]=i;
            }
        }

        return  mini==INT_MAX ? -1 : mini;
    }
};