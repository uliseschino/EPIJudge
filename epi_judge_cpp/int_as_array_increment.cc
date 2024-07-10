#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  int n = A.size();

  vector<int> B;
  B.reserve(n);

  for(int i=n-1; i >= 0; i--) {
    B.push_back(A[i]);
  }
  int carry = 1;
  for(int i=0; i < n; i++) {
    int temp = B[i] + carry;
    B[i] = temp % 10;
    carry = temp / 10;
  }
  if(carry > 0) {
    B.push_back(carry);
  }

  vector<int> result;
  result.reserve(n);

  for(int i=B.size() -1; i >= 0; i--) {
    result.push_back(B[i]);
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
