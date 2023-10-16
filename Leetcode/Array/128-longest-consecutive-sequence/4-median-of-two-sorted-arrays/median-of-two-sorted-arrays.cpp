class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int array1left = 0, array2left = 0;
        vector<int> num3;
        double mean = 0; 

        while (array1left < nums1.size() && array2left < nums2.size()) {
            if (nums1[array1left] < nums2[array2left]) {
                num3.push_back(nums1[array1left]);
                array1left++;
            } else {
                num3.push_back(nums2[array2left]);
                array2left++;
            }
        }

        while (array1left < nums1.size()) {
            num3.push_back(nums1[array1left]);
            array1left++;
        }

        while (array2left < nums2.size()) {
            num3.push_back(nums2[array2left]);
            array2left++;
        }

        int length = num3.size();

        if (length % 2 != 0) {
            mean = num3[length / 2];
        } else {
            mean = static_cast<double>(num3[length / 2] + num3[length / 2 - 1]) / 2.0;
        }

        return mean;
    }
};
