class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int max = cur;
        int min = (cur < 0) ? cur: 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            cur += nums[i];
            // fwd_sums.push_back(cur);
            if (cur - min > max) {
                max = cur - min;
                // cout << cur << ",max:" << max << "; ";
            } else if (cur < min) {
                min = cur;
                // cout << cur << ",min:" << min << "; ";
            } 
            // else {
            //     cout << cur << "; ";
            // }
        }
        return max;
    }
};
