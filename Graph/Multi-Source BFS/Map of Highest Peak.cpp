// Approach 1:
// TC: O(m*n)
// SC: O(m*n)
class Solution {
 public:
  int m, n;
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // R L U D

  void processHeight(vector<vector<int>>& isWater, vector<pair<int, int>>& waterCells) {
    queue<pair<int, int>> que;                            // SC: O(m*n)
    vector<vector<bool>> visited(m, vector<bool>(n, 0));  // SC: O(m*n)

    for (auto& [water_i, water_j] : waterCells) {
      que.push({water_i, water_j});
      visited[water_i][water_j] = true;
    }

    que.push({-1, -1});  // level breaker
    int level = 1;

    while (!que.empty()) {
      auto [i, j] = que.front();
      que.pop();

      if (i == -1 && j == -1) {  // level breaker
        if (!que.empty()) {
          que.push({-1, -1});
          level++;
        }
        continue;
      }

      for (auto& dir : directions) {
        int i_ = i + dir[0];
        int j_ = j + dir[1];

        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
          visited[i_][j_] = true;
          isWater[i_][j_] = level;
          que.push({i_, j_});
        }
      }
    }
  }
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    // Multi source BFS

    m = isWater.size();                 // Row
    n = isWater[0].size();              // Col
    vector<pair<int, int>> waterCells;  //SC: O(m*n)

    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (isWater[i][j]) {
          isWater[i][j] = 0;
          waterCells.push_back({i, j});
        }
      }
    }
    processHeight(isWater, waterCells);  // TC: O(m*n)
    return isWater;
  }
};
const auto init = []() {
  ios::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);
  return 1;
};
