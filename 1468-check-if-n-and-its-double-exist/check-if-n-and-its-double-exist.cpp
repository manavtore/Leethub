class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;

        for(int curr : arr){
            if((st.find(curr/2) != st.end() && curr%2==0) || st.find(curr*2) != st.end()){
                return true;
            }
            st.insert(curr);
        }
        return false;
    }
};