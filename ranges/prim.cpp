#include <iostream>
#include <range/v3/all.hpp>

using std::cout;
using std::endl;
using namespace ranges;

int main()
{
  // infinite range of squares:
  // does not work:
  //auto rng = view::ints(1) | view::transform([](int i){return i*i;});
  auto rng = view::ints(1);
  // sum the first 10 elements
  //int sum = accumulate(rng | view::transform([](int i){return i*i;}) | view::take(10), 0);

int sum = accumulate(view::ints(1)
                   | view::transform([](int i){return i*i;})
                   | view::take(10), 0);

  cout << sum << endl;
}
