class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 256> seen{0};
        for (char c: s) {
            seen[static_cast<size_t>(c)] += 1;
        }
        for (char c: t) {
            seen[static_cast<size_t>(c)] -= 1;
        }
        for (auto i: seen) {
            if (i != 0)
                return false;
        }
        return true;
    }
};
