// Approach 1: Optimal
// TC: O(n)
// Sc: O(1)
class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {  // TC: O(n)
      sum ^= derived[i];
    }
    /*
        if sum is zero, then every elemeent occured twice in original[]
        hence: derived can be achieved
        else it's not possible get derived[]
    */
    return sum == 0;
  }
};

// Approach 2:
// TC: O(n)
// Sc: O(1)
class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();

    int originalStart0 = 0;  // Assuming orginal[0] as 0
    int originalStart1 = 1;  // Assuming orginal[0] as 1

    for (int i = 0; i < n - 1; i++) {  // TC: O(n)
      originalStart0 ^= derived[i];
      originalStart1 ^= derived[i];
    }
    if ((originalStart0 ^ 0) == derived[n - 1]) return true;
    if ((originalStart1 ^ 1) == derived[n - 1]) return true;

    return false;
  }
};

// Approach 3:
// TC: O(2n) -> O(n)
// Sc: O(1)
class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();

    // Assuming orginal[0] as 0
    int curOriginal = 0;
    for (int i = 0; i < n - 1; i++) {  // TC: O(n)
      curOriginal = curOriginal ^ derived[i];
    }
    if (curOriginal ^ 0 == derived[n - 1]) return true;

    // Assuming orginal[0] as 1
    curOriginal = 1;
    for (int i = 0; i < n - 1; i++) {  // TC: O(n)
      curOriginal = curOriginal ^ derived[i];
    }
    if (curOriginal ^ 1 == derived[n - 1]) return true;
    return false;
  }
};

// Approach 1:
// TC: O(2n) -> O(n)
// SC: O(n)
class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    vector<int> original;

    // Assuming orginal[0] as 0
    original.push_back(0);
    for (int i = 0; i < n - 1; i++) {
      original.push_back(original.back() ^ derived[i]);
    }
    if (original.back() ^ original.front() == derived[n - 1]) return true;

    // Assuming orginal[0] as 1
    original.clear();
    original.push_back(1);
    for (int i = 0; i < n - 1; i++) {
      original.push_back(original.back() ^ derived[i]);
    }
    if (original.back() ^ original.front() == derived[n - 1]) return true;
    return false;
  }
};