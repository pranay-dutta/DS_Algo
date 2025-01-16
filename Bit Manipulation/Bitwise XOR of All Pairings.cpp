// Approach 1:
// TC: O(m+n)
// SC: O(1)
class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int n1Xor = 0, n2Xor = 0;
    if (n % 2 != 0) {  // O(m)
      for (int& y : nums2) {
        n2Xor ^= y;
      }
    }
    if (m % 2 != 0) {  // O(n)
      for (int& x : nums1) {
        n1Xor ^= x;
      }
    }

    return n1Xor ^ n2Xor;
  }
};

// Approach 2:
// TC: O(n+m+k) -> O(n)
// TC: O(k) -> O(n)
class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int64_t> mp;  // SC: O(n)
    int n = nums1.size();
    int m = nums2.size();

    for (int& x : nums1) {  // TC: O(n)
      mp[x] += m;
    }
    for (int& y : nums2) {  // TC: O(m)
      mp[y] += n;
    }

    // Traversing the map and XORing only the odd freq ones
    int res = 0;
    for (auto& [x, f] : mp) {  // TC: O(k)
      if (f & 1) res ^= x;
    }
    return res;
  }
};
