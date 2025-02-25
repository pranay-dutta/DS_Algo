// Approach 1:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int n = arr.size(), mod = 1e9 + 7;

    vector<int> cumSum(n, 0);  // O(n)
    cumSum[0] = arr[0];

    for (int i = 1; i < n; i++) {  // O(n)
      cumSum[i] = cumSum[i - 1] + arr[i];
    }

    int subarrCnt = 0;
    int evenCnt = 1, oddCnt = 0;   // consider 0 as even
    for (int i = 0; i < n; i++) {  // O(n)

      if (cumSum[i] & 1) {  // odd
        subarrCnt = (subarrCnt + evenCnt) % mod;
        oddCnt++;
      } else {
        subarrCnt = (subarrCnt + oddCnt) % mod;
        evenCnt++;
      }
    }
    return subarrCnt;
  }
};