class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (size_t i = m; i > 0; i--) {
            nums1[i + n - 1] = nums1[i - 1];
        }
        size_t i1 = n, i2 = 0;
        size_t i = 0;
        for (; i1 < nums1.size() && i2 < n; i++) {
            if (nums1[i1] <= nums2[i2]) {
                nums1[i] = nums1[i1];
                i1++;
            } else {
                nums1[i] = nums2[i2];
                i2++;
            }
        }
        for(; i2 < n; i++) {
                nums1[i] = nums2[i2];
                i2++;
        }
    }
};