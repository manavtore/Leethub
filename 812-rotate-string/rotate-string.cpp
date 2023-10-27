class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        int n =s.length();
       for(int i=0;i<n;i++){
            if(s==goal){
                return true;
            }

            s = s.substr(n-1)+s.substr(0,n-1);
       }

       return false;
        
    }

};