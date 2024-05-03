class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1);
        istringstream v2(version2);
        
        int num1, num2;
        char dot;
        
        while (v1.good() || v2.good()) {
            num1 = num2 = 0;
            v1 >> num1;
            v2 >> num2;
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            v1 >> dot;
            v2 >> dot;
        }
        
        return 0;
    }
};