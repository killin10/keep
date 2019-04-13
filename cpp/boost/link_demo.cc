/**
 * show how to link to boost binary
 *
 * @date Fri Nov  3 23:25:00 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>

#include <boost/regex.hpp>

int main()
{
	std::string line;
	boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

	while (std::cin)
	{
		std::getline(std::cin, line);
		boost::smatch matches;
		if (boost::regex_match(line, matches, pat))
			std::cout << matches[2] << std::endl;
	}

	return 0;
}
