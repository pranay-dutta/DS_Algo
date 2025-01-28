// Approach 1: using DFS
// TC: O(m*n)
// TC: O(1) | Only stack space
class Solution {
 public:
  int m, n;
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int maxFishesDFS(int i, int j, vector<vector<int>>& grid) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
      return 0;
    }

    int fishCnt = grid[i][j];  // count current-water fishes
    grid[i][j] = 0;            // exhausted all fish

    for (auto& dir : directions) {
      int i_ = dir[0] + i;
      int j_ = dir[1] + j;
      fishCnt += maxFishesDFS(i_, j_, grid);
    }
    return fishCnt;
  }
  int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int maxCatchableFish = 0;

    // O(m*n) -- Each cell will be visited once
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          maxCatchableFish =
              max(maxCatchableFish, maxFishesDFS(i, j, grid));  // O(m*n)
        }
      }
    }

    return maxCatchableFish;
  }
};

// Approach 2: using BFS
// TC: O(m*n)
// SC: O(m*n)
class Solution {
 public:
  int m, n;
  vector<vector<int>> directions = {
      {0, 1}, {0, -1}, {-1, 0}, {1, 0}};  // R L U D
  int maxFishesBFS(int i, int j, vector<vector<int>>& grid) {
    queue<pair<int, int>> que;  // SC: O(m*n)
    que.push({i, j});

    int countFish = grid[i][j];
    grid[i][j] = 0;  // caught all fishes of source

    while (!que.empty()) {
      auto [i, j] = que.front();
      que.pop();

      for (auto& dir : directions) {
        int i_ = i + dir[0];
        int j_ = j + dir[1];

        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] != 0) {
          que.push({i_, j_});
          countFish += grid[i_][j_];
          grid[i_][j_] = 0;
        }
      }
    }
    return countFish;
  }
  int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int maxCatchableFish = 0;

    // time: O(m*n)
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          maxCatchableFish = max(maxCatchableFish, maxFishesBFS(i, j, grid));
        }
      }
    }

    return maxCatchableFish;
  }
};

// Approach 3: using disjoing set union
// TC: O(m*n *a(m*n))
// SC: O(m*n)
// Time complexity of DSU's standard methods is Inverse Ackermann function:
// O(a(n))
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
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) return;  // parent is same

    if (size[x_parent] > size[y_parent]) {
      parent[y_parent] = x_parent;
      size[x_parent] += size[y_parent];
    } else {
      parent[x_parent] = y_parent;
      size[y_parent] += size[x_parent];
    }
  }

  void setSize(int idx, int fishCount) { size[idx] = fishCount; }

  // return the count of max number of fishes from size array
  int getMaxFishCount() { return *max_element(begin(size), end(size)); }
};

class Solution {
 public:
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    DSU dsu(m * n);  // 2D -> 1D //SC: O(m*n)
    int maxCatchableFish = 0;

    // Time: O(m*n * a(m*n))
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          int idx1D = i * n + j;
          dsu.setSize(idx1D, grid[i][j]);  // O(a(m*n))
        }
      }
    }

    // Time: O(m*n * a(m*n))
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] > 0) {   // if water cell found
          int idx = i * n + j;  // A

          for (auto& dir : directions) {
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;

            if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && grid[i_][j_] > 0) {
              int idx_ = i_ * n + j_;  // B
              dsu.Union(idx, idx_);    // union(A, B) with ngbr  //TC: O(a(m*n))
            }
          }
        }
      }
    }

    return dsu.getMaxFishCount();
  }
};
