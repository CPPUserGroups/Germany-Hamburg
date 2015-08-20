constexpr int fib(int n) 
{
#if __cplusplus < 201402L
  return n<2?1:fib(n-1)+fib(n-2);
#else
  if (n < 2) return 1;
  else return fib(n-1)+fib(n-2);
#endif
}

int main()
{
  static_assert(fib(1) == 1, "fib");
  static_assert(fib(7) == 21, "fib");
  static_assert(fib(41) == 267914296, "fib");
}
