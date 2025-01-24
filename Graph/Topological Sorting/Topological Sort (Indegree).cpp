class Solution {
 public:
  // Function to return list containing vertices in Topological order.
  vector<int> topologicalSort(vector<vector<int>>& adjList) {
    int n = adjList.size();

    vector<int> inDegree(n, 0);
    queue<int> q;

    //1. Calcuate inDegree
    for (int u = 0; u < n; u++) {
      for (int& v : adjList[u]) {
        inDegree[v]++;
      }
    }

    //2. Create queue and push all nodes with indeg of 0
    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) q.push(i);  // push those nodes having indeg of 0
    }

    vector<int> res;

    //3. Perform topological sort by repeatedly removing nodes with indeg of 0
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      res.push_back(u);
      for (int& v : adjList[u]) {
        inDegree[v]--; //reduce indeg of ngbr
        if (inDegree[v] == 0) q.push(v);
      }
    }
    return res;
  }
};