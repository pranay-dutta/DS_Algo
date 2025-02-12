// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int digitSum(int n) {  // O(9)
    int x = 0;
    while (n) {
      x += n % 10;
      n /= 10;
    }
    return x;
  }
  int maximumSum(vector<int>& nums) {
    int map[82] = {0};
    int maxSum = 0;

    for (int& num : nums) {  // O(n)
      int sum = digitSum(num);

      if (map[sum]) {
        maxSum = max(maxSum, map[sum] + num);
      }
      map[sum] = max(map[sum], num);
    }

    return maxSum == 0 ? -1 : maxSum;
  }
};

// Approach 2:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  int digitSum(int n) {  // O(9)
    int x = 0;
    while (n) {
      x += n % 10;
      n /= 10;
    }
    return x;
  }
  int maximumSum(vector<int>& nums) {
    unordered_map<int, priority_queue<int>> mp;  // set is in decendingorder

    for (int x : nums) {        // O(n)
      mp[digitSum(x)].push(x);  // O(log n)
    }

    int maxSum = 0;
    for (auto [x, maxHeap] : mp) {  //~O(82)
      if (maxHeap.size() >= 2) {  // if atleast 2 number exist of same digitsum
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();

        int sum = x + y;
        maxSum = max(sum, maxSum);
      }
    }
    return maxSum == 0 ? -1 : maxSum;
  }
};