// Approach 1:
// TC: O(m*n * log(m*n))
// SC: O(m*n)
class Solution {
 public:
  int m, n;
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  //{R, L, U, D}
  int dijkstra(vector<vector<int>>& grid) {
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));  // stores the costs
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    pq.push({0, 0, 0});  //{source, i, j}
    cost[0][0] = 0;

    while (!pq.empty()) {  // O(m*n)
      auto cur = pq.top();
      pq.pop();  // O(log(size of pq))

      int curCost = cur[0];
      int i = cur[1];
      int j = cur[2];

      if (cost[i][j] < curCost) continue;

      for (int dir_i = 0; dir_i <= 3; dir_i++) {
        int newi = i + dir[dir_i][0];
        int newj = j + dir[dir_i][1];

        if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
          int gridDir = grid[i][j];
          int dirCost = gridDir - 1 != dir_i ? 1 : 0;
          int newCost = curCost + dirCost;

          if (newCost < cost[newi][newj]) {
            cost[newi][newj] = newCost;
            pq.push({newCost, newi, newj});
          }
        }
      }
    }
    return cost[m - 1][n - 1];
  }
  int minCost(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    return dijkstra(grid);
  }
};
