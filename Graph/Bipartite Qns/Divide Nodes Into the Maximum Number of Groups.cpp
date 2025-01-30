// Approach 1: Bipartite graph
// TC: O(V * (V+E))
// SC: O(V+E)
class Solution {
 public:
  // 1 - Red, 0 - Green
  bool DFS(int u, int curColor, vector<vector<int>>& adjList, vector<int>& color) {
    color[u] = curColor;

    // Color the ngbrs
    for (int& v : adjList[u]) {
      if (color[v] == color[u]) return false;
      if (color[v] == -1) {  // color isn't assigned yet
        int colorOfV = !curColor;
        if (DFS(v, colorOfV, adjList, color) == false) {
          return false;
        }
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> color(n, -1);

    // 1 - n nodes
    for (int u = 1; u < n; u++) {  // O(V) each node will be visied once inside dfs also
      if (color[u] == -1 && !DFS(u, 0, adjList, color)) {
        return false;
      }
    }
    return true;
  }
  // Calculating each node's max level
  int BFS(int u, vector<vector<int>>& adjList, int n) {
    vector<int> visited(n, false);  // SC: O(V)
    visited[u] = true;

    queue<int> que;
    que.push(u);
    que.push(-1);  // level separator

    int level = 0;
    while (!que.empty()) {
      int u = que.front();
      que.pop();

      if (u == -1) {
        if (!que.empty()) {
          que.push(-1);  // add new spearator
        }
        level++;
        continue;  // skip -1 node
      }

      for (int& v : adjList[u]) {
        if (!visited[v]) {
          visited[v] = true;
          que.push(v);
        }
      }
    }
    return level;
  }

  // Returns maxLevel from each connected component
  int getMaxLevel(int u, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& levels) {
    visited[u] = true;
    int maxLvl = levels[u];

    for (int& v : adjList[u]) {
      if (!visited[v]) {
        maxLvl = max(maxLvl, getMaxLevel(v, adjList, visited, levels));
      }
    }
    return maxLvl;
  }
  int magnificentSets(int n, vector<vector<int>>& edges) {
    n += 1;                          // 1 - n nodes
    vector<vector<int>> adjList(n);  // SC: O(V+E)

    for (auto& edge : edges) {  // TC: O(E)
      int u = edge[0];
      int v = edge[1];
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }

    // if any connected component isn't bipartite(ie. can't be divided into
    // groups) return -1
    if (!isBipartite(adjList)) return -1;  // TC: O(V)

    vector<int> levels(n);  // SC: O(V)

    // time: O(V * (V+E)) --Highest term
    for (int u = 1; u < n; u++) {      // TC: O(V)
      levels[u] = BFS(u, adjList, n);  // O(V+E)
    }

    // Get max group(ie. level) from each connected component
    int maxGroupsFromEachComponent = 0;
    vector<bool> visited(n, false);  // SC: O(V)
    for (int u = 1; u < n; u++) {    // TC: O(V)
      if (!visited[u]) {
        maxGroupsFromEachComponent += getMaxLevel(u, adjList, visited, levels);
      }
    }
    return maxGroupsFromEachComponent;
  }
};
