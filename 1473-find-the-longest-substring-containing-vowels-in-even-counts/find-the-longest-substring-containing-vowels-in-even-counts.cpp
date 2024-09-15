class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        int res = 0, mask = 0;
        unordered_map<int, int> mask_to_idx;
        mask_to_idx[0] = -1;

        for(int i=0;i<s.size();i++){

            size_t pos = vowels.find(s[i]);
            
            if(pos != string::npos){
                mask ^= (1 << pos);
            }
            if(mask_to_idx.count(mask)){
                res = max(res,i - mask_to_idx[mask]);
            }else{
                mask_to_idx[mask]=i;
            }
        }
        return res;
    }
};