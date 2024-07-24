#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockTwice(const vector<double>& prices) {
  int n = prices.size();

  vector<double> max_forwards(n, 0);
  double min_so_far = std::numeric_limits<double>::max();
  double max_gain = 0;
  for(int i=0; i < n; i++) {
    min_so_far = std::min(min_so_far, prices[i]);
    max_gain = std::max(max_gain, prices[i] - min_so_far);
    max_forwards[i] = max_gain;
  }

  vector<double> max_backwards(n, 0);
  double max_so_far = std::numeric_limits<double>::min();
  max_gain = 0;
  for(int i=n-1; i >= 0; i--) {
    max_so_far = std::max(max_so_far, prices[i]);
    max_gain = std::max(max_gain, max_so_far - prices[i]);
    max_backwards[i] = max_gain;
  }

  double result = 0;
  for(int i=0; i < n; i++) {
    result = std::max(result, max_forwards[i] + max_backwards[i]);
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
