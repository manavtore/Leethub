class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
         int maxright=-1;
        for(int i=arr.size()-1;i>=0;i--){
          int currentelement=arr[i];
           arr[i]=maxright;
          maxright = max(currentelement,maxright);
         
        }
        return arr;
    }
};