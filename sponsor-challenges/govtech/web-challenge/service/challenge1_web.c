#include <string>
#include <iostream>
#include <bitset>
#include <sstream>

bool decode4(std::string input, std::string flag, bool display=false);
std::string encode4(std::string input);
void challenge1(std::string input, bool hasInput);
void challenge2(std::string input, bool hasInput);
void intro();

int main(int argc, char ** argv) {


	std::string command = argv[1];

	if (argc == 2) {
	
		if (command == "intro") {
			intro();
		}

		if (command == "challenge1") {
			challenge1("", false);
		}

	}	
	else if (command == "challenge1") {
		if (argc == 3) {
			std::string input = argv[2];
			challenge1(input, true);
		}	
	}
	else if (command == "challenge2") {
		std::string input;
		challenge2(input, true);
	}


	return 0;
}

void intro() {
//	for (auto i=0u; i<100u; ++i) {
//		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//	}
	std::cout << "***** Welcome to the first GovTech challenge ***** <br>" << std::endl;
	std::cout << "There are a total of 2 sub puzzles for the first challenge. <br>" << std::endl;
	std::cout << "The two challenges are linked. <br>" << std::endl;
	std::cout << "Solving the first puzzle will help in the second puzzle if the challenger truly understands how to solve the first puzzle<br>" << std::endl;
	std::cout << "Press enter to begin<br>" << std::endl;
//	std::string null;
//	std::getline(std::cin, null);
}


void challenge1(std::string input, bool hasInput) {

	std::string flag = "BCBCBADABCABBABDBDCDBDBABCBBBCADBCCABBDDBAACBCABBDADBCBBADBABDDB";

	if (hasInput) {

		if (decode4(input,flag,true)) {

			std::cout << "TRUE";
			return;
		}
		else {
			std::cout << "<br><b>Flag does not match!</b><br> Try harder." << std::endl;
			std::cout << "<br><br>The encodeded flag is: <br>" << std::endl;
			std::cout << flag << std::endl;

			return;
		}

	}



	std::cout << "The encodeded flag is: <br>" << std::endl;
	std::cout << flag << std::endl;
	std::cout  << "<br>Clue 1: The first four characters are \"fLaG\".<br><br>" << std::endl << "Any input entered will be encoded and displayed to help the challenger.<br><br>" << std::endl << std::endl;

}



void challenge2(std::string input, bool hasInput) {
//	std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << "************ SECOND CHALLENGE ***************" << std::endl << std::endl;

	std::cout << "Please enter your name." << std::endl << "Name: ";

	std::string challenger_name;

	while (challenger_name == "") {
		std::getline(std::cin, challenger_name);

		if (challenger_name == "") {
			continue;
		}
	}

	std::cout << "Welcome " + challenger_name + "." << std::endl;

	std::string flag = encode4("flag{govtech_" + challenger_name + "}");

	std::cout << "The encodeded flag is: " << std::endl;
	std::cout << flag << std::endl;
	std::cout << "The encoded flag displayed is encoded using base4, try to get the decoded flag." << std::endl << "No output will be given to the challenger's input." << std::endl << std::endl;


	while (1) {
		std::string input;
		std::getline(std::cin,  input);

		if (decode4(input,flag)) {

			std::cout << "Congrats challenger. Find KHOR TECK CHUNG for your prize indicating your name with the decoded flag." << std::endl;
			return;
		}
		else {
			std::cout << "Try harder." << std::endl << std::endl;
			continue;
		}
	}
}


bool decode4(std::string input, std::string flag, bool display) {


	std::string compare = encode4(input);

	if (compare == flag) {
		return true;
	}
	if (display) {
		std::cout << "Encoded input: " << compare << std::endl;
	}

	return false;
}

std::string encode4(std::string input) {

	std::stringstream ss(input);
	std::string compare;
	unsigned char a;
	while (ss >> a) {
		std::string bin_a;
		for (int i=0; i<8; ++i) {
			if (a >> (7-i) & 0x1) {
				bin_a.push_back('1');
			}
			else {
				bin_a.push_back('0');
			}
		}

		for (int i=0; i<4; ++i) {
			std::string seq = bin_a.substr(i*2,2);
			if (seq == "00") {
				compare.push_back('A');
			}
			else if (seq == "01") {
				compare.push_back('B');
			}
			else if (seq == "10") {
				compare.push_back('C');
			}
			else if (seq == "11"){
				compare.push_back('D');
			}
			else {
				std::cout << "Invalid sequence " + seq << std::endl;
				std::exit(1);
			}

		}


	}

	return compare;


}
