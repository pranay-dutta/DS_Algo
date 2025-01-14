// Approach 1: Bitset
// TC: O(50n) -> O(n)
// SC: O(51+51) -> O(101) -> O(1)
class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    bitset<51> x = 0, y = 0;  // SC: O(51*2)
    vector<int> res(n);

    for (int i = 0; i < n; i++) {  // TC: O(n)
      int a = A[i], b = B[i];
      x[a] = 1;
      y[b] = 1;

      // counting those bits who are set in both
      res[i] = (x & y).count();  // TC: O(50)
    }
    return res;
  }
};

// Approach 2:
// TC: O(n)
// SC: O(1) //because memory usage does not scale with the input size n
class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    // count of numbers that are present in both A & B till i
    int n = A.size();

    vector<int> mp(51, 0);  // SC: O(1)
    vector<int> res(n);
    int commonCount = 0;

    for (int i = 0; i < n; i++) {  // TC: O(n)
      mp[A[i]]++;
      mp[B[i]]++;

      if (A[i] == B[i]) {
        commonCount++;
        res[i] = commonCount;
        continue;
      }

      if (mp[A[i]] == 2) commonCount++;
      if (mp[B[i]] == 2) commonCount++;
      res[i] = commonCount;
    }
    return res;
  }
};

// Approach 3:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();

    vector<int> mp(n + 1, 0), res(n);  // SC: O(n)
    int commonCount = 0;

    for (int i = 0; i < n; i++) {  // TC: O(n)
      mp[A[i]]++;
      if (mp[A[i]] == 2) commonCount++;

      mp[B[i]]++;
      if (mp[B[i]] == 2) commonCount++;

      res[i] = commonCount;
    }
    return res;
  }
};

// Approach 4: unordered_map
// TC: O(n)
// SC: O(n) --Memory grow dynamically
class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    // count of numbers that are present in both A & B till i
    unordered_map<int, int> mp;
    int n = A.size();
    vector<int> res(n);
    int commonCount = 0;

    for (int i = 0; i < n; i++) {
      mp[A[i]]++;
      mp[B[i]]++;

      if (A[i] == B[i]) {
        commonCount++;
        res[i] = commonCount;
        continue;
      }

      if (mp[A[i]] == 2) commonCount++;
      if (mp[B[i]] == 2) commonCount++;
      res[i] = commonCount;
    }
    return res;
  }
};