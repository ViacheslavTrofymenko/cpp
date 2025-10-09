/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:12:12 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 12:13:31 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool	checkArguments(int argc, char **argv, std::string &filename, std::string &s1, std::string &s2)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
		return (false);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty.\n";
		return (false);
	}
	return (true);
}

std::string	replaceAll(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string result;
	size_t pos = 0;

	while (true)
	{
		size_t found = line.find(s1, pos);
		if (found == std::string::npos)
		{
			result.append(line.substr(pos));
			break;
		}
		result.append(line.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.length();
	}

	return (result);
}

void processFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream input(filename.c_str());
	if (!input)
	{
		std::cerr << "Error: cannot open file " << filename << " for reading.\n";
		return ;
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream output(outputFilename.c_str());
	if (!output)
	{
		std::cerr << "Error: cannot open file " << outputFilename << " for writing.\n";
		return ;
	}
	std::string line;
	while (std::getline(input, line))
	{
		std::string result = replaceAll(line, s1, s2);
		output << result;
		if (!input.eof())
			output << '\n';
	}
	input.close();
	output.close();
	std::cout << "File processed successfully: " << outputFilename << "\n";
}

int main(int argc, char **argv)
{
	std::string filename, s1, s2;

	if (!checkArguments(argc, argv, filename, s1, s2))
		return 1;

	processFile(filename, s1, s2);
	return 0;
}
