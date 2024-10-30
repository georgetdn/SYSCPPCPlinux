#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>


#include "Database.h"
#include "Record.h"
###includes

std::string toUpperCase(const std::string& str);
void InitializeVector(std::vector<std::vector<std::string>>& vecOfVecs);
void InitializeDesc(std::vector<std::vector<std::string>>& vecOfDesc);
bool checkSyntax(std::vector<std::string>& tokens);
std::vector<std::string> split(std::string& s);

std::vector<std::vector<std::string>> vecOfVecs;
std::vector<std::vector<std::string>> vecOfDesc;
###declarations
Database db;



int main(int argc, char* argv[]) 
{
	if (argc < 2)
	{
		std::cout << "Usage:\n SmallSQL(DB file name)\nIf the file does not exist it will be created" << std::endl;
		return 1;
	}

	db.Connect(argv[1]);

	std::string input;

	std::cout << "Welcome to SmalSQL!" << std::endl;
	std::cout << "Supported commands: DESC, SELECT, INSERT, DELETE, UPDATE, CLS, HELP" << std::endl;
	std::cout << "'select from dual' supports 'classes', 'count()', 'date', 'dbname' and 'dump' " << std::endl << std::endl;

	InitializeVector(vecOfVecs);
	InitializeDesc(vecOfDesc);
	Record::db->outFile.seekp(0, std::ios::beg);
	while (true) {
		std::cout << "SmallSQL> ";
		std::getline(std::cin, input);

		if (input.empty()) {
			continue;
		}
		if (toUpperCase(input) == "EXIT" || toUpperCase(input) == "QUIT" || toUpperCase(input) == "BYE") {
			break;
		}

		std::vector<std::string> tokens = split(input);

		if (checkSyntax(tokens)) {
			// Further command execution logic can be added here.
		}
	}

	std::cout << "Exiting SmallSQL." << std::endl;
	return 0;
}
