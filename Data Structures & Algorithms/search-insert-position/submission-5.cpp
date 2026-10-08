class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() < 1) { return 0; }
        size_t start = 0;
        size_t end = nums.size() - 1;
        while(true) {
            if (nums[end] < target) { return static_cast<int>(++end); }
            if (nums[start] > target) { return static_cast<int>(start); }
            if (start == end) { return static_cast<int>(end); }
            size_t i = start + (end - start) / 2 ;
            if (nums[i] < target) {
                start = i + 1;
            } else if (nums[i] == target) {
                return i;
            } else {
                end = i - 1;
            }
        }
    }
};