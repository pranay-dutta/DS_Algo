// Approach 1: Optimal
// TC: O(m*n)
// SC: O(m+n)
class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> serverCountRowWise(m);
    vector<int> serverCountColWise(n);

    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          serverCountRowWise[i]++;
          serverCountColWise[j]++;
        }
      }
    }
    // Counting connected servers
    int connectedServers = 0;
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 &&
            (serverCountRowWise[i] > 1 || serverCountColWise[j] > 1)) {
          connectedServers++;
        }
      }
    }

    return connectedServers;
  }
};
// Approach 2:
// TC: O(m*n)
// SC: O(m*n)
class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    vector<pair<int, int>> servers;

    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) servers.push_back({i, j});
      }
    }

    int connectedServers = 0;                    // count of connected servers
    for (int i = 0; auto& [i_, j_] : servers) {  // O(m*n)
      bool connected = false;

      for (int j = 0; auto& [server_i, server_j] : servers) {
        if (i != j && (i_ == server_i || j_ == server_j)) {
          connected = true;
          break;
        }
        j++;
      }
      if (connected) connectedServers += 1;
      i++;
    }

    return connectedServers;
  }
};
// Approach 3: Brute force
// TC: O(m*n)
// SC: O(m*n)
class Solution {
 public:
  int m, n;
  int DFS(vector<pair<int, int>>& servers, vector<vector<int>>& grid) {
    int totalConnectedServers = 0;
    for (auto& server : servers) {
      auto [i_, j_] = server;
      bool connected = false;

      int i = i_;
      int j = j_;

      // Right
      for (int i = i_ + 1; i < m; i++) {
        if (connected) break;
        if (grid[i][j]) connected = 1;
      }
      // Left
      for (int i = i_ - 1; i >= 0; i--) {
        if (connected) break;
        if (grid[i][j]) connected = 1;
      }
      // Up
      for (int j = j_ + 1; j < n; j++) {
        if (connected) break;
        if (grid[i][j]) connected = 1;
      }
      // Down
      for (int j = j_ - 1; j >= 0; j--) {
        if (connected) break;
        if (grid[i][j]) connected = 1;
      }

      if (connected) totalConnectedServers += 1;
    }
    return totalConnectedServers;
  }
  int countServers(vector<vector<int>>& grid) {
    // Multi source DFS

    vector<pair<int, int>> servers;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) servers.push_back({i, j});
      }
    }
    int connectedServers =
        DFS(servers,
            grid);  // TC: O(m*n) //Because each cell will get only visited once
    return connectedServers;
  }
};