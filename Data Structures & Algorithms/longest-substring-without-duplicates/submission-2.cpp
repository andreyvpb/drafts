class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        array<size_t, 256> seen;
        seen.fill(50001);
        size_t max = 0, start = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            size_t c = static_cast<size_t>(s[i]);
            if (seen[c] != 50001 && seen[c] >= start) {  
                if (max < i - start) {
                    max = i - start;
                }
                start = seen[c] + 1;
            }
            seen[c] = i;
            //cout << i << " | " << c << " | " << (i - start) << " | " << max << endl;
        }
        if (max < s.length() - start) {
            max = s.length() - start;
        }
        return static_cast<int>(max);
    }
};
