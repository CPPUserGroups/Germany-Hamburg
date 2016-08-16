#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <iostream>
#include <vector>

int main() 
{
  std::vector<int> vec{1,2,3,4,1,2,3,4,1,3,2,4};
  boost::copy( boost::sort(vec) | boost::adaptors::uniqued,
               std::ostream_iterator<int>(std::cout) );
}
