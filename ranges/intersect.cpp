#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

auto intersect(const std::string& a, const std::string& b)
{
  using cset = std::set<char>;
  auto as = cset{std::begin(a),std::end(a)};
  auto bs = cset{std::begin(b),std::end(b)};
  cset res;
  std::set_intersection(std::begin(as),std::end(as),std::begin(bs),std::end(bs),
     std::inserter(res, std::begin(res)));
  return res;
}

int main()
{
  auto res = intersect("abasdflj", "aklsjdflkj");
  std::copy(std::begin(res),std::end(res), std::ostream_iterator<char>(std::cout,""));
}
