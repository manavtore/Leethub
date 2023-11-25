class Solution {
public:
    int strStr(string haystack, string needle) {

        size_t foundIndex = haystack.find(needle);

        if(foundIndex != string::npos ) {
            return foundIndex;
        }
        return -1;
        
        

    }
};