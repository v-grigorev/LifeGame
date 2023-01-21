#include <iostream>
#include "Game.h"
#include "Reader.h"
#include <Windows.h>
#include <memory>
#include "Command.h"
#include "CommandLineHandler.h"
#include "CommandFactory.h"
#include "LifeException.h"
#include "StringUtilities.h"

using namespace std;

int main(int argc, char* argv[]) {
	shared_ptr<Game> game;
	string cmdLine;
	CommandFactory cmdFactory;

	if (argc != 1) {
		try {
			CommandLineHandler::Handle(argc, argv);
		}
		catch (const LifeException& ex) {
			cout << ex.what() << endl;
		}
		return 0;
	}

	while (1) {
		cout << "<life> ";
		getline(cin, cmdLine);
		if (cmdLine == "exit") {
			break;
		}
		if (cmdLine == "help") {
			cmdFactory.Help();
			continue;
		}

		vector<string> vecCmd = StringUtilities::Split(cmdLine);
		if (vecCmd.size() == 0) {
			continue;
		}

		
		try {
			shared_ptr<Command> cmd = cmdFactory.GetCommand(vecCmd[0]);
			game = cmd->DoCommand(game, vecCmd);
		}
		catch (const LifeException& ex) {
			cout << ex.what() << endl;
		}
	};
	return 0;
}
