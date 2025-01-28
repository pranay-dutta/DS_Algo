// Approach 1: Not optimal
// TC: O(m*n *(m*n))
// SC: O(m*n)
class Solution {
 public:
  int m, n;
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};  // R L U D
  int maxFishesBFS(int i, int j, vector<vector<int>>& grid) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));  // SC: O(m*n)

    queue<pair<int, int>> que;  // SC: O(m*n)
    que.push({i, j});
    visited[i][j] = true;  // mark start as visited

    int countFish = grid[i][j];

    while (!que.empty()) {  //(m*n)
      auto [i, j] = que.front();
      que.pop();

      for (auto& dir : directions) {
        int i_ = i + dir[0];
        int j_ = j + dir[1];

        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] &&
            grid[i_][j_] != 0) {
          visited[i_][j_] = true;  // mark current cell as visited

          que.push({i_, j_});
          countFish += grid[i_][j_];
        }
      }
    }
    return countFish;
  }
  int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    vector<pair<int, int>> waterCells;  // O(m*n)
    // Time: O(m*n)
    for (int i = 0; i < m; i++) {    // TC: O(m)
      for (int j = 0; j < n; j++) {  // TC: O(n)
        if (grid[i][j]) {
          // coordinate of water cell
          waterCells.push_back({i, j});
        }
      }
    }

    int maxCatchableFish = 0;
    // Time: O(m*n * (m*n))
    for (auto& [i, j] : waterCells) {  // O(m*n)
      maxCatchableFish = max(maxCatchableFish, maxFishesBFS(i, j, grid));
    }
    return maxCatchableFish;
  }
};
