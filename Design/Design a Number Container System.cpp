// Approach 1:
// TC: O(n)
// SC: O(n)
class NumberContainers {
 private:
  // space: O(n)
  unordered_map<int, set<int>> container;  // O(n)
  unordered_map<int, int> indices;         // O(n)
 public:
  NumberContainers() {};
  void change(int index, int number) {
    int num = indices[index];         // Which number was in this index
    container[number].insert(index);  // O(n)
    indices[index] = number;
    if (num && num != number) container[num].erase(index);  // O(n)
  }

  int find(int number) {  // TC: O(1)
    auto it = container[number].begin();
    if (it == container[number].end()) return -1;
    return *it;
  }
};