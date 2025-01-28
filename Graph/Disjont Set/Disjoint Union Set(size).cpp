class DSU {
 private:
  vector<int> parent;
  vector<int> size;

 public:
  DSU(int n) {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++) {
      size[i] = 1;    // initial size is 1
      parent[i] = i;  // each set is parent of his own
    }
  }

  int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);  // path compression
  }
  void Union(int x, int y) {
    int x_parent = find_set(x);
    int y_parent = find_set(y);
    if (x_parent == y_parent) return;  // parent is same

    if (size[x_parent] > size[y_parent]) {
      parent[y_parent] = x_parent;  
      size[x_parent] += size[y_parent];

    } else {
      parent[x_parent] = y_parent;  
      size[y_parent] += size[x_parent];
    }
  }
};
