#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

#include <boost/range/algorithm.hpp>
//using ranges = ranges::v3;
//using namespace ranges;

auto intersect(const std::string& a, const std::string& b)
{
  using cset = std::set<char>;
  cset res;
  auto iter = std::inserter(res, std::begin(res));

  //return boost::range::set_intersection(boost::range::sort(a), boost::range::sort(b), iter);
  boost::range::set_intersection(cset{a.begin(),a.end()}, cset{b.begin(),b.end()}, iter);
  return res;
}

int main()
{
  const std::string a{"abasdflj"}, b{"aklsjdflkj"};
  auto res = intersect(a,b);
  std::copy(std::begin(res),std::end(res), std::ostream_iterator<char>(std::cout,""));
}
