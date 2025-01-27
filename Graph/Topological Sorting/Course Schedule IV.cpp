// Approach 1: Kahn's Algorithm
// TC: O(V^2 + V + E)
// SC: O(V+E)
class Solution {
 public:
  void topoSort(vector<vector<int>>& adjList, unordered_map<int, unordered_set<int>>& mp) {
    int n = adjList.size();

    vector<int> indeg(n, 0);  // O(n)
    queue<int> q;

    // 1. calculate indeg
    for (int u = 0; u < n; u++) {
      for (int& v : adjList[u]) {
        indeg[v]++;
      }
    }

    // 2. create and push all nodes with indeg of 0
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0) q.push(i);
    }

    // 3. process transitive dependencies
    // TC: O(V+E * V)
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int& v : adjList[u]) {
        mp[v].insert(u);                   // came from u to v
        for (const int& prereq : mp[u]) {  // O(V)
          mp[v].insert(prereq);
        }

        indeg[v]--;  // reduce indeg of neighbours
        if (indeg[v] == 0) q.push(v);
      }
    }
  }
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;              // number of nodes
    vector<vector<int>> adjList(n);  // SC: O(V+E)

    // Build adjacency List
    for (auto& edge : prerequisites) {  // TC: O(E)
      int u = edge[0];
      int v = edge[1];
      adjList[u].push_back(v);  // edge u->v
    }

    unordered_map<int, unordered_set<int>> mp;  //
    topoSort(adjList, mp);

    vector<bool> res;

    // Process each query
    for (auto& query : queries) {
      int u = query[0];
      int v = query[1];

      if (mp[v].contains(u)) {
        res.push_back(true);  // Means that there is a path from u-->v
      } else {
        res.push_back(false);
      }
    }
    return res;
  }
};
// Approach: 3 (Using DFS) You can use BFS as well
// T.C : O(Q * (V+E))
// S.C : O(V+E)
class Solution {
 public:
  bool DFS(int u, int v, vector<vector<int>>& adjList, vector<bool>& visited) {
    int n = adjList.size();

    visited[u] = true;
    if (visited[v]) return true;

    bool res = false;
    for (int& ngbr : adjList[u]) {
      if (!visited[ngbr] && !visited[v]) {
        res |= DFS(ngbr, v, adjList, visited);
      }
    }
    return res;
  }

  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;              // number of nodes
    vector<vector<int>> adjList(n);  // SC: O(V+E)

    // Build adjacency List
    for (auto& edge : prerequisites) {  // TC: O(E)
      int u = edge[0];
      int v = edge[1];
      adjList[u].push_back(v);  // edge u->v
    }

    vector<bool> res;
    // TC: O(Q * (V+E))
    for (auto& query : queries) {  // TC: O(Q)
      vector<bool> visited(n, false);
      int u = query[0];
      int v = query[1];

      res.push_back(
          DFS(u, v, adjList, visited));  // O(V+E) {Can also be done with BFS}
    }
    return res;
  }
};

// Approach 3:
// TC: O(V^2 * (V+E))
// SC: O(V+E)
class Solution {
 public:
  bool DFS(int u, int v, vector<vector<int>>& adjList, vector<bool>& visited) {
    int n = adjList.size();

    visited[u] = true;
    if (visited[v]) return true;

    bool res = false;
    for (int& ngbr : adjList[u]) {
      if (!visited[ngbr] && !visited[v]) {
        res |= DFS(ngbr, v, adjList, visited);
      }
    }
    return res;
  }

  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;              // number of nodes
    vector<vector<int>> adjList(n);  // SC: O(V+E)

    // Build adjacency List
    for (auto& edge : prerequisites) {  // TC: O(E)
      int u = edge[0];
      int v = edge[1];
      adjList[u].push_back(v);  // edge u->v
    }

    // preprocess who's prerequisites of whose
    vector<vector<bool>> processedDFS(n, vector<bool>(n, false));  // O()

    for (int u = 0; u < n; u++) {  // TC: V^2
      for (int v = 0; v < n; v++) {
        if (u != v) {
          // is there is a possible path from u-->v ?
          vector<bool> visited(n, false);
          processedDFS[u][v] = DFS(u, v, adjList, visited);  // TC: O(V+E)
        }
      }
    }

    vector<bool> res;
    for (auto& query : queries) {  // TC: O(Q)
      int u = query[0];
      int v = query[1];

      res.push_back(processedDFS[u][v]);
    }
    return res;
  }
};