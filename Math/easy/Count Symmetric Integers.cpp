// TC: ~O(n * d) d = 7
// SC: O(1)
class Solution {
 public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; i++) {  // O(n * d)
      int x = i, len = 0, lsum = 0, rsum = 0;
      int digit[5];

      while (x) {  // TC: 5
        digit[len] = x % 10;
        x /= 10;
        len++;
      }

      if (len % 2 == 0) {  // if has positive number of digits
        int half = len / 2;

        for (int j = 0; j < half; j++) {  // TC: x / 2
          lsum += digit[j];               // left half
          rsum += digit[half + j];        // right half
        }
        if (lsum == rsum) count++;
      }
    }
    return count;
  }
};
