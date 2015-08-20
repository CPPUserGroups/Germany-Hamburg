#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
  constexpr int i = 42;
  static_assert(i == 42, "i is the answer");
  auto j = &i;
  int *pi = const_cast<int*>(j);
  assert(pi == &i);
  *pi = 23;
  assert(*pi == 23);
  cout << *pi << ':' << i << endl;
}
