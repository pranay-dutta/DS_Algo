// Approach 1:
// TC: O(SQRT(n))
// SC: O(1)
class Solution {
 public:
  bool isPrime(int n) {
    if (n == 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
  }
  vector<int> closestPrimes(int left, int right) {
    // 1. find primes
    // 2. find smallest diff
    // 3. return the answer

    vector<int> primes;
    for (int i = left; i <= right; i++) {
      if (isPrime(i)) primes.push_back(i);
    }

    int diff = INT_MAX;
    vector<int> res(2, -1);
    if (primes.size() < 2) return {-1, -1};

    for (int i = 0; i < primes.size() - 1; i++) {
      if ((primes[i + 1] - primes[i]) < diff) {
        diff = primes[i + 1] - primes[i];
        res[0] = primes[i];
        res[1] = primes[i + 1];
      }
    }
    return res;
  }
};
