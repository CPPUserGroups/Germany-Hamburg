constexpr int sqrt(int i)
{
  return i/2;
}

int main()
{
  static_assert(sqrt(4) == 2, "sqrt");
  static_assert(sqrt(81) == 9, "sqrt");
  static_assert(sqrt(17*17) == 17, "sqrt");
}
