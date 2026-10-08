class Solution {
    // Recursive
    int searchInsertIter(vector<int>& nums, int target, size_t start, size_t end) {
        if (nums[end] < target) { return static_cast<int>(++end); }
        if (nums[start] > target) { return static_cast<int>(start); }
        if (start == end) { return static_cast<int>(end); }
        size_t i = start + (end - start) / 2 ;
        if (nums[i] < target) {
            return searchInsertIter(nums, target, i + 1, end);
        } else if (nums[i] == target) {
            return i;
        } else {
            return searchInsertIter(nums, target, start, i - 1);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() < 1) { return 0; }
        return searchInsertIter(nums, target, 0, nums.size() - 1);
    }
};