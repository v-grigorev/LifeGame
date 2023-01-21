#include "Load.h"
#include "Reader.h"
#include <iostream>

shared_ptr<Game> Load::DoCommand(shared_ptr<Game> game, const vector<string>& argv) {
	shared_ptr<Game> newGame;
	if (argv.size() == 1) {
		newGame = make_shared<Game>();
	}
	else {
		newGame = Reader::Read(argv[1]);
	}
	cout << newGame->GetName() << " loaded" << endl;
	return newGame;
}

string Load::GetName() {
	return "load";
}

string Load::Help() {
	return "Load universe from file.\n1 argument: input file name\n";
}
