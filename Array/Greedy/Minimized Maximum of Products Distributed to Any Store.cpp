class Solution {
 public:
  bool isDistributable(int eachStoreGets, vector<int>& q, int shops) {
    // can expProd be distributable ----

    for (int prod : q) {
      /* ceil(float(a) / float(b))  =>  (a+b-1)/b */

      // needed to distribute current product and each store gets: eachStoreGets
      shops -= ceil(float(prod) / float(eachStoreGets));   // maximum this many shops
      if (shops < 0)
        return false;  // shops exhausted but still product is remaining
    }
    return true;
  }
  int minimizedMaximum(int n, vector<int>& q) {
    int l = 1, r = *max_element(begin(q), end(q));
    int ans = 0;

    // Choose a product between 1 to max value of quantities
    while (l <= r) {
      int mid = (l + r) / 2;

      if (isDistributable(mid, q, n)) {
        r = mid - 1;  // ans found but searching for lower ans
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};