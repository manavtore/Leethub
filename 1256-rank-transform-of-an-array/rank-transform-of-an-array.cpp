class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        vector<int> sortedArr(arr.begin(),arr.end());
        sort(sortedArr.begin(),sortedArr.end());

        int rank=1;
        for(int num:sortedArr){
            if(mp.find(num)==mp.end()){
                mp[num]=rank;
                rank++;
            }
        }
        vector<int> ans(n,0);
        for(int i=0 ; i < n ; i++){
            ans[i] = mp[arr[i]]; 
        }

        return ans;
    }
};