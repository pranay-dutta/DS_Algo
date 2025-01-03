// Approach 1:
//TC: O(2n - 2) -> O(n)
//SC: O(2n) -> O(n)
class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    vector<long long> LcumSum(n);
    vector<long long> RcumSum(n);
    long long sum1 = 0, sum2 = 0;
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
      sum1 += nums[i];
      sum2 += nums[j];

      LcumSum[i] = sum1;
      RcumSum[j] = sum2;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (RcumSum[i] >= LcumSum[i + 1]) {
        ans += 1;
      }
    }
    return ans;
  }
};
//Approach 2:
//TC: O(accumulate + n) -> O(n)
//SC: O(1) 
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int64_t rightSum = 0, leftSum = 0;
        rightSum = accumulate(begin(nums), end(nums), 0LL);

        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if(leftSum >= rightSum) ans++;
        }
        return ans;
    }
};
