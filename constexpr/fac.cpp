constexpr int fac(int n) 
{
#if __cplusplus < 201402L
  return n<2?1:n*fac(n-1);
#else
  int res = 1;
  for (;n > 1;--n) res *= n;
  return res;
#endif
}

int main()
{
  static_assert(fac(1) == 1, "fac");
  static_assert(fac(7) == 5040, "fac");
}
