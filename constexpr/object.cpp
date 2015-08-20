
struct A {
  int val;
  constexpr A(int i) : val(i) {}
  constexpr int f() { ++val; return val; } // c++11 error: *this is const
};

int main()
{
  constexpr A a(42);
  //constexpr auto av = a.f(); // will fail
  A b(23);
  auto bv = b.f();
}
