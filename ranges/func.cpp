#include <iostream>
#include <vector>
#include <cassert>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext/erase.hpp>

template<typename R>
void print(const char* prefix, const R& r) {
  std::cout << prefix << ": ";
  boost::copy(r,std::ostream_iterator<int>(std::cout)); 
  std::cout << '\n';
}

int main()
{
  const std::vector<int> baseVec{1,1,2,2,3,4,4,4,4,7};
  std::vector<int> vec = baseVec;
  print("vec", vec);
  print("unique", boost::unique(vec));
  // print("unique", boost::unique(vec));  <-- next call to unique will fail -> why?


  vec = baseVec;
  print("found_end", boost::unique<boost::return_found_end>(vec));
  vec = baseVec;
  print("begin_next", boost::unique<boost::return_begin_next>(vec));
  vec = baseVec;
  print("next_end", boost::unique<boost::return_next_end>(vec));
  vec = baseVec;
  print("begin_end", boost::unique<boost::return_begin_end>(vec));

  // Anwendung:
  vec = baseVec;
  std::vector<int> uniqueVec = boost::erase(vec, boost::unique<boost::return_found_end>(vec));
  print("erase",uniqueVec);
}
