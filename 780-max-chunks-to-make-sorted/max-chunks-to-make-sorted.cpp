class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
       int count=0;
       int maxelement=0;
       if(arr.size()==0){
           return 1;
       }
        for(int i=0;i<arr.size();i++){
        maxelement=max(maxelement,arr[i]);
            if(maxelement==i){
                count++;
            }

        }
        return count;
    }
};