class Solution {
public:
    void backtrack(int& maxlength,vector<string>& arr,string current,int index){
        maxlength=max(maxlength,(int)current.length());

        for(int i=index;i<arr.size();i++){
            if(isUnique(current+arr[i])){
                 backtrack(maxlength,arr,current+arr[i],i+1);
            }
        }
    }
    int maxLength(vector<string>& arr) {
        int maxlength=0;
        backtrack(maxlength,arr,"",0);
        return maxlength;
    }
    bool isUnique(string s){
        vector<bool> seen(26,false);
        for(char c:s){
            if(seen[c-'a']){
                return false;
            }
            seen[c-'a']=true;
        }
        return true;
    }
};