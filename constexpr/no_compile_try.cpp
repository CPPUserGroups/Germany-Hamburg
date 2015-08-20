#include <stdexcept>

constexpr int may_throw(int i)
{
  if (i%2) throw std::logic_error("");
  else return i;
}

constexpr int func(int i) {
    if (i < 1) throw std::logic_error("!");
    else if (i == 1) return 1;
    else 
      try {
        return may_throw(i); }
      catch (...) {
      return i; }
  }

int main()
{
  auto i = func(1);
}
