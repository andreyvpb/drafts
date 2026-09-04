class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int max = cur;
        int min = (cur < 0) ? cur : 0;
        const int* head = nums.data();
        const int* tail = head + nums.size();
        for (const int* p = head + 1; p < tail; ++p) {
            cur += *p;
            if (cur - min > max) {
                max = cur - min;
            } else if (cur < min) {
                min = cur;
            }
        }
        return max;
    }
};
