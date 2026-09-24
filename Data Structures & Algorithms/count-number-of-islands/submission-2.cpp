class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        size_t rows = grid.size();
        // if (rows < 1) { return 0; }
        size_t cols = grid[0].size();
        queue<pair<size_t, size_t>> adjQ;
        for (size_t r = 0; r < rows; ++r) {
            for (size_t c = 0; c < cols; ++c) {
                auto x = grid[r][c];
                // cout << "grid(" << r << ", " << c << ") = " << x << endl;
                if (x == '1') {
                    ++ret;
                    grid[r][c] = '0';
                    adjQ.emplace(r, c);
                    while (!adjQ.empty()) {
                        auto pos = adjQ.front();
                        adjQ.pop();
                        if (pos.second > 0 && grid[pos.first][pos.second - 1] == '1') {
                            grid[pos.first][pos.second - 1] = 0;
                            adjQ.emplace(pos.first, pos.second - 1);
                        }
                        if (pos.second + 1 < cols && grid[pos.first][pos.second + 1] == '1') {
                            grid[pos.first][pos.second + 1] = 0;
                            adjQ.emplace(pos.first, pos.second + 1);
                        }
                        if (pos.first > 0 && grid[pos.first - 1][pos.second] == '1') {
                            grid[pos.first - 1][pos.second] = 0;
                            adjQ.emplace(pos.first - 1, pos.second);
                        }
                        if (pos.first + 1 < rows && grid[pos.first + 1][pos.second] == '1') {
                            grid[pos.first + 1][pos.second] = 0;
                            adjQ.emplace(pos.first + 1, pos.second);
                        }
                        grid[pos.first][pos.second] = '0';
                    }
                }
            }
        }
        return ret;
    }
};
