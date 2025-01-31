// Approach 1:
// TC: O((m*n) * a(m*n))
// SC: O(m*n)
class DSU {
 private:
  vector<int> parent;
  vector<int> size;

 public:
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 0);

    for (int i = 0; i < n; i++) {
      parent[i] = i;  // each set is parent of his own
    }
  }

  int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);  // path compression
  }
  void Union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;  // parent is same

    if (size[x] > size[y]) {
      parent[y] = x;
      size[x] += size[y];
    } else {
      parent[x] = y;
      size[y] += size[x];
    }
  }
  void setSize(int idx, int s) { size[idx] = s; }
  int getSize(int idx) {
    int parrent = find(idx);
    return size[parrent];
  }
};
class Solution {
 public:
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // R L U D
  int m, n;
  void unionLands(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, DSU& dsu) {
    queue<pair<int, int>> que;  // cordinate

    visited[i][j] = true;
    que.push({i, j});

    while (!que.empty()) {
      auto [i, j] = que.front();
      que.pop();
      int idx = i * n + j;

      for (auto& dir : directions) {
        int i_ = dir[0] + i;
        int j_ = dir[1] + j;
        int idx_ = i_ * n + j_;

        if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && !visited[i_][j_] &&
            grid[i_][j_]) {
          visited[i_][j_] = true;
          que.push({i_, j_});
          dsu.Union(idx, idx_);  // TC: O(a(m*n))
        }
      }
    }
  }
  int processWater(int i, int j, vector<vector<int>>& grid, DSU& dsu) {
    int idx = i * n + j;
    int size = 1;

    unordered_set<int> uniqueParents;
    for (auto& dir : directions) {
      int i_ = dir[0] + i;
      int j_ = dir[1] + j;
      int idx_ = i_ * n + j_;

      if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
        int parentIdx = dsu.find(idx_);
        uniqueParents.insert(parentIdx);
      }
    }
    for (int idx : uniqueParents) {
      size += dsu.getSize(idx);
    }
    return size;
  }
  int largestIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    DSU dsu(m * n);  // 2D->2D  //SC: O(m*n)

    // Time: O(m*n * a(m*n))
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        int idx = i * n + j;
        dsu.setSize(idx, grid[i][j]);  // O(a(m*n))
      }
    }

    // union exisiting 1s(islands)
    vector<vector<bool>> visited(m, vector<bool>(n, false));  // SC: O(m*n)

    // Time: O(m*n)
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          unionLands(i, j, grid, visited, dsu);
        }
      }
    }

    int largestIsland = 0;
    // Time: O(m*n)
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          largestIsland = max(largestIsland, processWater(i, j, grid, dsu));  // O(4 * a(m*n))
        }
      }
    }
    return largestIsland == 0 ? (m * n) : largestIsland;
  }
};