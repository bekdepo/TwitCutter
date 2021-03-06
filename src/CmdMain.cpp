// TwitCutter
//
// CmdMain.cpp
// Main source file for command-line access to the application
#include <string>
#include <iostream>
#include <cstdio>
#include "GenericProc.h"

enum AppControls
{
	APP_CONT  = -1,
	APP_ERR   = 0,
	APP_OUT   = 1,
	APP_RESET = 999
};

enum Extensions
{
	NOFILE,
	DOC,
	TXT
	// PDF,
	// DOCX,
	// RTF,
	// etc.
};

int check_opt(char);
int check_ext(std::string&);

int main(int argc, char** argv)
{
	int control(APP_RESET);
	std::string path;

	while (true)
	{
		if (argc == 1)
		{
			// Invoke Copyright notice
			std::cout << "File path: ";
			std::getline(std::cin, path);
			std::cout << std::endl;
		}
		else if (argc > 2)
		{
			std::cerr << "Illegal number of arguments." << std::endl;
			return 1;
		}
		else
		{
			path = argv[1];
		}

		if (path.length() > FILENAME_MAX)
		{
			std::cerr << "Path is too long for this application." << std::endl;
			return 2;
		}

		// Parse file extension
		std::string::size_type dot = path.rfind('.');
		std::string exte = path.substr(dot);

		int tag = check_ext(exte);			// sink this value into processor?
		if (tag == NOFILE)
		{
			break;
		}

		// Process file contents
		GenericProc docjob;
		docjob.globalProcess(path);

		// Global control options
		char opt{};
		std::cout << "Operation completed." << std::endl;
		std::cout << "Quit? (Y/N): ";
		std::cin >> opt;

		control = check_opt(opt);

		if (control == APP_OUT)
		{
			break;
		}
		else if (control == APP_CONT || control == APP_ERR)
		{
			if (control == APP_ERR)
			{
				std::cerr << "Invalid. Repeating prompt..." << std::endl;
			}

			continue;
		}
	}
	
	return 0;
}

// Checks input options that control main loop
int check_opt(char c)
{
	if (tolower(c) == 'y')
	{
		return 1;
	}
	else if (tolower(c) == 'n')
	{
		return -1;
	}
	return 0;
}

// Checks file extension
int check_ext(std::string &str)
{
	int len = str.length() + 1;
	char *tempstr = new (std::nothrow) char[len];
	if (tempstr == nullptr)
	{
		std::cerr << "Unable to allocate memory." << std::endl;
		delete[] tempstr;
		return -1;
	}
	
	// Ensure all lower-case
	for (int i = 0; i < len; ++i)
	{
		tempstr[i] = tolower(str[i]);
	}
	tempstr[len] = '\0';

	str.assign(tempstr);

	if (str == ".doc")
	{
		return DOC;
	}
	else if (str == ".txt")
	{
		return TXT;
	}
	else
	{
		std::cerr << "App does not handle '" << str << "' files!" << std::endl;
	}
	return 0;
}
