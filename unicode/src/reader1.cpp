#include <iostream>
#include <fstream>
#include <algorithm>


int main(int argc,char **argv)
{
	std::ifstream input(argv[1]);
	std::string buffer ;
	std::getline(input,buffer);

	std::for_each(buffer.begin(),buffer.end(),[](char value) { std::cout<<value<<std::endl; });

	std::cout<<buffer<<std::endl;

	return 0;
		
}
