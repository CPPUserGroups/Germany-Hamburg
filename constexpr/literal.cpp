#include <iostream>
#include <type_traits>

struct A {
  std::string s;
};

int f() { return 2; };

int main()
{
  std::cout << std::is_literal_type<std::string>::value << '\n';
  std::cout << std::is_literal_type<A>::value << '\n';
  std::cout << std::is_literal_type<A*>::value << '\n';
  std::cout << std::is_literal_type<A&>::value << '\n';
  std::cout << std::is_literal_type<decltype(f)>::value << '\n';
}
  
