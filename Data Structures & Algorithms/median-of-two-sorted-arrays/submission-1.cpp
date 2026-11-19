class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result;
        int i  = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        while (i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        double ans;
        if ((m + n) % 2 != 0)
            ans = (double)result[(m + n) / 2];
        else {
            int mid1 = (m + n) / 2;
            int mid2 = mid1 - 1;
            int x = result[mid1], y = result[mid2];
            ans = ((double)x + y) / 2.0;
        }
        return ans;
    }
};
