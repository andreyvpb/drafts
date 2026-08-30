class Solution {
public:
    bool isAnagram(string s, string t) {
        auto l = s.length();
        if (l != t.length()) {
            return false;
        }
        array<int, static_cast<size_t>('z' - 'a' + 1)> seen{0};
        for (size_t i = 0; i < l; i++) {
            seen[static_cast<size_t>(s[i] - 'a')]++;
            seen[static_cast<size_t>(t[i] - 'a')]--;
        }
        for (auto i: seen) {
            if (i != 0)
                return false;
        }
        return true;
    }
};