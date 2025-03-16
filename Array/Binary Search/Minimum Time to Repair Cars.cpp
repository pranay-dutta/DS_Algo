// Approach (binary serach on answer)
// TC: O(n * log(maxRank*cars*cars));
// SC: O(1)

class Solution {
 public:
  typedef long long ll;
  bool isRepairable(vector<int>& ranks, ll time, int cars) {
    // time = r * (n^2) -- simple math rick  /r is the rank
    // n^2 = time / r -- sqrt to remove the square and get the car count
    // n = sqrt(time / r)

    ll carsFixed = 0;
    for (int i = 0; i < ranks.size(); i++) {
      carsFixed += sqrt(time / ranks[i]);  // n number of cars
    }
    return carsFixed >= cars;
  }
  ll repairCars(vector<int>& ranks, int cars) {
    // e :Time = if highest rank mechanic assigned to repair all the cars
    ll n2 = (long)cars * (long)cars;
    ll highestRank = *max_element(begin(ranks), end(ranks));
    ll s = 1, e = highestRank * n2;

    // try to minimize the time
    ll minTimeToRepair = 0;
    while (s <= e) {
      ll mid = s + (e - s) / 2;  // time

      if (isRepairable(ranks, mid, cars)) {
        minTimeToRepair = mid;
        e = mid - 1;  // try to minize the time
      } else {
        s = mid + 1;
      }
    }
    return minTimeToRepair;
  }
};