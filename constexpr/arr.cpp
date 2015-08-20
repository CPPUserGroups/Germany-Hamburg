#include <array>
#include <utility>

template<typename T, size_t... I>
constexpr std::array<T,sizeof...(I)> make_array_impl(T initVal, const std::index_sequence<I...>&)
{
  return { ((void)I, initVal)... };
}

template<typename T, size_t N>
constexpr std::array<T,N> make_array(T initVal)
{
  return make_array_impl(initVal, std::make_index_sequence<N>());
}

int main()
{
  constexpr std::array<int,2> a({23,24});
  static_assert(a.size() == 2, "size a");
  static_assert(a[0] == 23 && a[1] == 23, "value b");

  constexpr auto b = make_array<int,2>(42);
  static_assert(b.size() == 2, "size b");
  static_assert(b[0] == 42 && b[1] == 42, "value b");
}
