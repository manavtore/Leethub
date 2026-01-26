class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int mini = arr[1] - arr[0];


        for(int i=1;i<arr.size()-1;i++){
            mini = min(mini,arr[i+1]-arr[i]);
        }

        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};