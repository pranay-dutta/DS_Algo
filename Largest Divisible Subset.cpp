// TC: O(n^2)
// SC: O(n)
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    // state definition: t[i] = long increasing subseq ending at ith index

    int n = nums.size();
    sort(begin(nums), end(nums));

    vector<int> t(n, 1);
    vector<int> prevIdx(n, -1);

    int maxLIS = 1;
    int lastIdx = 0;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          if (t[i] < t[j] + 1) {
            t[i] = t[j] + 1;
            prevIdx[i] = j;
          }

          if (t[i] > maxLIS) {
            maxLIS = t[i];
            lastIdx = i;
          }
        }
      }
    }

    vector<int> res;
    while (lastIdx != -1) {
      res.push_back(nums[lastIdx]);
      lastIdx = prevIdx[lastIdx];
    }

    return res;
  }
};
