
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/schriter.h>
#include <unicode/regex.h>


int main(int argc,char **argv)
{
	if(argc<2)
	{
		std::cerr<<"Missing input file!"<<std::endl;
		return 1;
	}
	std::ifstream input(argv[1]);
	UErrorCode status = U_ZERO_ERROR;




	std::vector<icu::UnicodeString>  words;

	while(!input.eof())	
	{
		icu::UnicodeString buffer;
		input>>buffer;
		words.push_back(buffer);
	}

	std::sort(words.begin(),words.end());
	std::for_each(words.begin(),words.end(),[](const icu::UnicodeString &str) { std::cout<<str<<std::endl; });

	//
	// regular expressions
	//
	icu::UnicodeString pattern = UNICODE_STRING_SIMPLE("ن");
	icu::RegexMatcher matcher(pattern,0,status);

	std::cout<<std::endl<<"Search for words with Nun"<<std::endl;

	auto end = std::partition(words.begin(),words.end(),
			   [&matcher](const icu::UnicodeString &word)
			   { matcher.reset(word);
			   	 return matcher.find();
			   });
	std::for_each(words.begin(),end,[](const icu::UnicodeString &word) { std::cout<<word<<std::endl; });


	return 0;
		
}
