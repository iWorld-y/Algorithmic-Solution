Solution {
   public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ret;
        ret.resize(n - 2);
        for (int i = 0; i < n - 2; ++i) ret[i].resize(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int x = i + 1, y = j + 1;
                int mx = -1e9;
                for (int k = -1; k <= 1; ++k) {
                    for (int l = -1; l <= 1; ++l) {
                        mx = max(mx, grid[x + k][y + l]);
                    }
                }
                ret[i][j] = mx;
            }
        }
        return ret;
    }
};