class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() < 1) { return 0; }
        size_t start = 0;
        size_t end = nums.size();
        while(start < end) {
            size_t i = start + (end - start) / 2 ;
             if (nums[i] >= target) {
                end = i;
            } else {
                start = i + 1;
            }
        }
        return start;
    }
};