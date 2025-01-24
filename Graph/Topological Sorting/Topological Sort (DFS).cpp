#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void DFS(int u, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;

    for (int v : adjList[u]) {  // 1. Push childs into the stack
      if (!visited[v]) {
        DFS(v, adjList, visited, st);
      }
    }
    st.push(u);  // 2. At last push the parrent
  }
  vector<int> topoSort(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    stack<int> st;

    // DFS for all nodes, if not visited then DFS for that node
    for (int u = 0; u < n; u++) {
      if (!visited[u]) {
        DFS(u, adjList, visited, st); 
      }
    }

    vector<int> result;
    while (!st.empty()) { //build result
      result.push_back(st.top());
      st.pop();
    }
    return result;
  }
};
