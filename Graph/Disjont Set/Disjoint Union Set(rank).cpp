//DSU time complexity is denoted Inverse Ackermann  
class DSU {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  DSU(int v) {
    parent = vector<int>(v);
    rank = vector<int>(v, 0);  // initial rank of each set is 0

    for (int i = 0; i < v; i++) {
      parent[i] = i;  // each set is parent of his own
    }
  }

  int find(int i) { //TC: O(a(n))
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);  // path compression
  }
  
  void Union(int x, int y) { //TC: O(a(n))
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent == y_parent) return;  // parent is same

    if (rank[x_parent] < rank[y_parent]) {
      parent[x_parent] = y_parent;
    } else if (rank[y_parent] < rank[x_parent]) {
      parent[y_parent] = x_parent;
    } else {
      parent[x_parent] = y_parent;
      rank[y_parent]++;  // increase rank if both set have same rank
    }
  }
};
