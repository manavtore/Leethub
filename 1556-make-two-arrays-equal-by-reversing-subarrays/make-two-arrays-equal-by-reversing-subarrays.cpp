class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n1 = target.size();
        int n2 = target.size();
        if(n1!=n2) return false;

        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        if(target==arr){
            return true;
        }
        return false;
    }
};