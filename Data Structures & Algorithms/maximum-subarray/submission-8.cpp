class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int max = cur;
        int min = (cur < 0) ? cur: 0;
        for (auto it = nums.begin() + 1; it < nums.end(); ++it) {
            cur += *it;
            if (cur - min > max) {
                max = cur - min;
            } else if (cur < min) {
                min = cur;
            } 
        }
        return max;
    }
};
