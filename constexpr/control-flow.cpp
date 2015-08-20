#include  <stdexcept>
constexpr int f(int i) {
    if (i < 10) throw std::logic_error("wrong!");
  else return i+1;
}
constexpr auto i = f(23); // ok
auto j = f(7); // compile error
