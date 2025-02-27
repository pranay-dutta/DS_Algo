// Approach 1: using set
// TC: O(n^2)
// SC: O(n)
class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    unordered_set<int> st(begin(arr), end(arr));

    int longestSeq = 2;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        int prev = arr[i];
        int seq = 2;
        int next = arr[j];
        while (st.count(prev + next)) {
          int t = prev;  // string prev number as temp
          prev = next;
          next = t + next;
          seq++;
        }
        longestSeq = max(longestSeq, seq);
      }
    }

    return longestSeq == 2 ? 0 : longestSeq;
  }
};
