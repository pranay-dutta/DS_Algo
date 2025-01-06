// Approach 1: Most Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n, 0);

    int LCumVal = 0;
    int RCumVal = 0;

    int LCumValSum = 0;
    int RCumValSum = 0;

    for (int i = 0, j = n - 1; i < n; i++, j--) {  // O(n)
      ans[i] += LCumValSum;
      ans[j] += RCumValSum;

      LCumVal += boxes[i] - '0';
      RCumVal += boxes[j] - '0';

      LCumValSum += LCumVal;
      RCumValSum += RCumVal;
    }
    return ans;
  }
};
// Approach 2: Optimal
// TC: O(2n) -> O(n)
// SC: O(2n) -> O(n)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> cumSumL2R(n);
    vector<int> cumSumR2L(n);
    vector<int> ans(n, 0);

    int L2Rsum = 0;
    int R2Lsum = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {  // O(n)
      L2Rsum += boxes[i] - '0';
      R2Lsum += boxes[j] - '0';

      cumSumL2R[i] = i > 0 ? L2Rsum + cumSumL2R[i - 1] : L2Rsum;
      cumSumR2L[j] = j < n - 1 ? R2Lsum + cumSumR2L[j + 1] : R2Lsum;
    }

    for (int i = 0; i < n; i++) {  // O(n)
      ans[i] += i > 0 ? cumSumL2R[i - 1] : 0;
      ans[i] += i < n - 1 ? cumSumR2L[i + 1] : 0;
    }

    return ans;
  }
};
// Approach 3:
// TC: O(n^2)
// SC: O(n)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    unordered_set<int> idxs;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
      if (boxes[i] == '1') idxs.insert(i);
    }

    for (int i = 0; i < n; i++) {
      int move = 0;
      for (int j : idxs) {
        move += abs(j - i);
      }
      ans[i] = move;
    }
    return ans;
  }
};
// Approach 4: Brute force
// TC: O(n^2)
// SC: O(1)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int move = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (boxes[j] == '1') move += i - j;
      }
      for (int k = i + 1; k < n; k++) {
        if (boxes[k] == '1') move += k - i;
      }
      ans[i] = move;
    }
    return ans;
  }
};