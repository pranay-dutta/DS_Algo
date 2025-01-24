class Solution {
 public:
  bool isCycleDFS(int u, vector<bool>& visited, vector<bool>& inRecursion, vector<vector<int>>& adj) {
    visited[u] = true; //2. in next call it will be marked as visited
    inRecursion[u] = true;

    //Process neighbors of current source(u)
    for (int& v : adj[u]) {
      if (!visited[v] && isCycleDFS(v, visited, inRecursion, adj)) { //1. if not visited but contains cycle
        return true;
      } else if (inRecursion[v]) { //if visited but contains cycle
        return true;
      }
    }

    //if cycle not found in current recursion mark false
    inRecursion[u] = false; 
    return false;
  }

  bool isCyclic(int n, vector<vector<int>> adj) {
    //n is the number of nodes  ---

    vector<bool> visited(n, false); 
    vector<bool> inRecursion(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i] && isCycleDFS(i, visited, inRecursion, adj)) {
        return true;
      }
    }
    return false;
  }
};
