class ProductOfNumbers {
 private:
  vector<int> stream;  // O(1) : Worst case: 100
  int n;

 public:
  ProductOfNumbers() {
    stream.clear();  // clearing any obsolute value
    n = 0;
  }

  void add(int num) {  // TC: O(1)
    if (num == 0) {    // if num is zero reset the stream
      n = 0, stream.clear();
    } else {
      if (stream.empty()) stream.push_back(num);
      else stream.push_back(stream.back() * num);
      n++;
    }
  }

  int getProduct(int k) {  // TC: O(1)
    if (k > n) return 0;  // means till [n-k-1] we have seen at least one zero. so the product will be 0
    if (n == k) return stream.back();

    int totalProduct = stream.back();
    return totalProduct / stream[n - k - 1];  //[totalProduct / [n-k-1]] will give you rest of the prodct from [n-k-1] to [n-1]
  }
};
