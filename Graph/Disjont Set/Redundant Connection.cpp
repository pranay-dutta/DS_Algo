// Approach 1: using dfs
// TC: O(E *(V+E))
// SC: O(V+E)
class Solution {
 public:
  bool DFS(int source, int dest, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[source] = true;
    if (source == dest) return true;  // can reach source to dest

    bool found = false;
    for (int& ngbr : adjList[source]) {
      if (!visited[ngbr]) {
        found |= DFS(ngbr, dest, adjList, visited);
      }
    }
    return found;
  }
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    // SC: O(V+E)
    vector<vector<int>> adjList(n + 1);  // n nodes from 1 to n

    for (auto& edge : edges) {  // O(E)
      int u = edge[0];
      int v = edge[1];

      vector<bool> visited(n + 1);        // O(V)
      if (DFS(u, v, adjList, visited)) {  // O(V+E)
        return edge;
      }

      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    return {};
  }
};
// Approach 3:
// TC: O(e * a(n))
// SC: O(n)
class DSU {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  DSU(int n) {
    parent = vector<int>(n);
    rank = vector<int>(n);
    iota(begin(parent), end(parent), 0);
    fill(begin(rank), end(rank), 0);
  }
  int find(int x) {
    if (x == parent[x]) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }
  void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;  // same parrent

    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else if (rank[y] > rank[x]) {
      parent[x] = y;
    } else {
      parent[x] = y;
      rank[y]++;
    }
  }
  bool sameParent(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
  }
};
class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DSU dsu(n + 1);  // 1 to n nodes //SC: O(n)

    // time: O(e * a(n))
    for (auto& edge : edges) {  // TC: O(e)
      int u = edge[0];
      int v = edge[1];
      if (dsu.sameParent(u, v)) {  // TC: O(a(n))
        return edge;
      }
      dsu.Union(u, v);  // TC: O(a(n))
    }
    return {};
  }
};

// Approach 3: using bfs
// Time: O(E * (V+E))
// Space: O(V+E)
class Solution {
 public:
  bool BFS(int source, int dest, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
    visited[source] = true;

    queue<int> que;  // SC: O(v)
    que.push(source);

    while (!que.empty()) {  // TC: O(v+e)
      int u = que.front();
      que.pop();

      for (const int& ngbr : adjList[u]) {
        if (!visited[ngbr]) {
          if (dest == ngbr) return true;
          visited[ngbr] = true;
          que.push(ngbr);
        }
      }
    }
    return false;
  }
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    // space: O(v+e)
    unordered_map<int, vector<int>> adjList;  // n nodes from 1 to n

    // time: O(e * v+e)
    for (auto& edge : edges) {  // TC: O(e)
      int u = edge[0];
      int v = edge[1];

      vector<bool> visited(n + 1);        // SC: O(v)
      if (BFS(u, v, adjList, visited)) {  // TC: O(v+e)
        return edge;
      }

      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    return {};
  }
};