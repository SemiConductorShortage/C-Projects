#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <random>
float F(float C) {
	return ((C * 9 / 5) + 32);
}


float C(float F) {
	return ((F - 32) * 5 / 9);


}


float Convert() {
	std::cout << "C to F / F to C!\n";
	std::cout << "1-C to F\n2-F to C:\n";
	std::string option, num;
	getline(std::cin, option);
	std::cout << "Number:";
	if (option == "1") {
		getline(std::cin, num);
		return F(std::stof(num));
	}

	if (option == "2") {
		getline(std::cin, num);
		return C(std::stof(num));
	}

	else {
		return 0;
	}


}
std::string lowercase(std::string input) {
	std::string cheese;
	for (int i = 0; i < input.size(); i++) {cheese+=tolower(input[i]);}
	return cheese;


}
void programmer() {
	std::cout << "Input Testing!\n";

	std::cout << "Name a programmer : ";
	std::string cheese;
	getline(std::cin, cheese);
	std::cout << cheese << " is bad at C++";
}

using std::map; using std::string; using std::cout;
void rps() {
	std::random_device rand; // random number
	std::mt19937 gen(rand()); // seed
	std::uniform_int_distribution<> distr(1, 3); // range
	map<int, string> Table = {{1, "rock"},{2, "paper"},{3, "scissors"}};
	map<string, string> Attacking = { //Format {"this can attack", "this"}, so Attacking["paper"] will return rock
		{"paper","rock"},
		{"rock","scissors"},
		{"scissors","paper"}
	};
	string choice;
	cout << "Rock, paper or scissors?\n";
	getline(std::cin, choice);
	bool found = false;
	choice = lowercase(choice);
	string thing = Table[distr(gen)];

	for (int i = 0; i < 3; i++) { //There are only 3 items
		found = choice == Table[i]; //returns false if choice isnt the current item in the loop
		if (found) {break;}; // if its found, stop the loop to save that nanosecond of processing time
	}



	if (!found) { //if it isnt found after the loop
		cout<<"\nUse an actual option, dude\n"; //say the funnies
		return rps(); //restart function
	}

	if (Attacking[thing] == choice) { //If the bot can attack your selection:
		cout << "You lost against a C++ program made by a 14 year old. Nice.\nBot chose:" << thing << '\n';
	}

	if (thing == choice) { // If tied
		cout << "It's a tie, great job.\n";
	}

	if ((Attacking[thing] != choice) && (thing != choice)){ //If its neither tied or lost
	cout << "Bot chose " << thing << ", so you win (Or you bugged the program). Are you proud?\n";
	}

	cout << "Play Again? [y/n]";
	string choose;
	getline(std::cin, choose);
	if (choose == "y") { return rps(); };
}


int main() {
	std::cout << "Project Switcher!\n1-Name a programmer\n2-Celsius and Fahrenheit\n3-Rock, Paper, Scissors!\n";
	std::string option;
	getline(std::cin, option);
	if (option == "1") {
		std::cout << std::endl;
		programmer();
	}

	if (option == "2") {;
		std::cout << "\nResult:" << Convert() << "\n";
	}

	if (option == "3") {
		rps();
	}
}
