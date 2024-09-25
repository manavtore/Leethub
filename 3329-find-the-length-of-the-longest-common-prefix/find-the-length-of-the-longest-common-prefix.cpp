class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size()>arr2.size()){
            swap(arr1,arr2);
        }
        unordered_set<int> st;
        for(auto n:arr1){
            while(n && st.find(n) == st.end()){
                st.insert(n);
                n/=10;
            }
        }

        int res = 0;
        for(auto n:arr2){
            while(n && st.find(n)==st.end()){
                n/=10;
            }
            if(n){
                res = max(res,static_cast<int>(to_string(n).length()));
            }
        }
        return res;
    }
};