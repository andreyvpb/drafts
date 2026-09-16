class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        size_t l = nums.size();
        if (l <= 1) {
            return static_cast<int>(l);
        }

        unordered_set<int> seen(nums.begin(), nums.end());
        // unordered_set<int> seen(l));
        // for (int n: nums) {
        //     seen.insert(n);
        // }
        
        int max = 1;
        for (int n: nums) {
            int count = 1;
            if (auto iter = seen.find(n); iter != seen.end()) {
                    seen.erase(iter);
            } else {
                continue; // already found & removed
            }
            int backward = n - 1;   // TODO: potential issue - boudary check
            do {
                if (auto iter = seen.find(backward); iter != seen.end()) {
                    --backward;
                    ++count;
                    seen.erase(iter);
                } else {
                    break;
                }
            } while (true);
            int forward = n + 1;// TODO: potential issue - boudary check
            do {
                if (auto iter = seen.find(forward); iter != seen.end()) {
                    ++forward;
                    ++count;
                    seen.erase(iter);
                } else {
                    break;
                }
            } while (true);
            if (count > max) {
                max = count;
            }
        }

        return max;
    }
};
