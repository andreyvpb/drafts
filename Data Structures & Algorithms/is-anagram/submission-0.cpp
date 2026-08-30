class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, size_t> seen(s.length());
        for (char c: s) {
            auto it = seen.find(c);
            if (it == seen.end()) { // not found
                seen[c] = 1;
            } else {
                seen[c] = it->second + 1;
            }
        }
        for (char c: t) {
            auto it = seen.find(c);
            if (it == seen.end()) { // not found
                return false;
            } else if (it->second == 1) {
                seen.erase(it);
            } else {
                it->second = it->second - 1;
            }
        }
        return seen.empty();
    }
};
