#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  double max_gain=0, min_so_far = std::numeric_limits<double>::max();
  for(double price: prices) {
    double gain = price - min_so_far;
    max_gain = std::max(max_gain, gain);
    min_so_far = std::min(min_so_far, price);
  }
  return max_gain;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
