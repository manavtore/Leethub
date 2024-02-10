class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void count(string& s,int start,int& cnt){
        if(start==s.length()){
            return;
        }
        for(int end=start;end<s.length();end++){
            if(isPalindrome(s,start,end)){
                cnt++;
            }
        }
        count(s,start+1,cnt);
    }
    int countSubstrings(string s) {
        int cnt=0;
        count(s,0,cnt);
        return cnt;
        
    }
};