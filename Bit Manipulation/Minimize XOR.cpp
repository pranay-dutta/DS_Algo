// Approach 1:
// TC: O(1)
// SC: O(1)
class Solution {
 public:
  int setBitCount(int n) {
    int bitCnt = 0;
    for (int i = 0; i < 32; i++) {
      if ((n >> i) & 1) bitCnt++;
    }
    return bitCnt;
  }
  int minimizeXor(int num1, int num2) {
    int x = num1;  // start x as num1 because their XOR is 0
    int requiredBit = setBitCount(num2);

    /*If x has less bit than required*/
    if (setBitCount(x) < requiredBit) {
      int bitsNeedToSet = requiredBit - setBitCount(x);
      for (int i = 0; i < 32 && bitsNeedToSet > 0; i++) {  // terminate if don't have bit's to set  TC: O(32)
        if ((x >> i) & 1) continue;  // skip if bit is already set
        else {
          x = x | (1 << i);
          bitsNeedToSet--;
        }
      }

      /*If x has more bit than required*/
    } else if (setBitCount(x) > requiredBit) {
      int bitsNeedToUnset = setBitCount(x) - requiredBit;
      for (int i = 0; i < 32 && bitsNeedToUnset > 0; i++) {  // terminate if don't have bits to unset //TC: O(32)
        if ((x >> i) & 1) {  // if bit is set unset it
          x = x & ~(1 << i);
          bitsNeedToUnset--;
        }
      }
    } else {
      /*Both number is same */
      x = num1;
    }
    return x;
  }
};

// Approach 2:
// TC: O(log(n))
// SC: O(1)
class Solution {
 public:
  bool isSet(int &x, int i) {  // check i'th bit is set or not
    return (x >> i) & 1;
  }
  void setBit(int &x, int i) {  // set i'th bit
    x |= (1 << i);
  }
  void unsetBit(int &x, int i) {  // unset i'th bit
    x &= ~(1 << i);
  }
  int minimizeXor(int num1, int num2) {
    int x = num1;
    int requiredSetBit = __builtin_popcount(num2);
    int currentSetBit = __builtin_popcount(x);

    int i = 0;  // start from LSB(least significant bit)
    if (currentSetBit < requiredSetBit) {
      while (currentSetBit < requiredSetBit) {
        if (!isSet(x, i)) {
          setBit(x, i);
          currentSetBit++;
        }
        i++;
      }
    } else if (currentSetBit > requiredSetBit) {
      while (currentSetBit > requiredSetBit) {
        if (isSet(x, i)) {
          unsetBit(x, i);
          currentSetBit--;
        }
        i++;
      }
    }
    return x;
  }
};
