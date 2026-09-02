class Solution {
   public:
    void reverseString(vector<char>& s) {
        for (size_t head = 0, tail = s.size() - 1; head < tail; ++head, --tail) {
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;
        }
    }
};