
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/schriter.h>


int main(int argc,char **argv)
{
	if(argc<2)
	{
		std::cerr<<"Missing input file!"<<std::endl;
		return 1;
	}
	std::ifstream input(argv[1]);

	icu::UnicodeString line_buffer;

	while(!input.eof())	
	{
		icu::UnicodeString buffer;
		input>>buffer;
		line_buffer += buffer;
	}

	std::cout<<"Entire line:"<<std::endl;
	std::cout<<line_buffer<<std::endl;

	std::cout<<"Character iteration"<<std::endl;
	icu::StringCharacterIterator iterator(line_buffer);
	std::cout<<UnicodeString(iterator.first())<<std::endl;
	while(iterator.hasNext())
	{
		std::cout<<UnicodeString(iterator.next())<<std::endl;
	}

	return 0;
		
}
