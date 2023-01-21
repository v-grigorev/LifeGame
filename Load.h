#pragma once
#include "Command.h"
#include <memory>

using namespace std;

class Load : public Command {
	shared_ptr<Game> DoCommand(shared_ptr<Game> game, const vector<string>& argv);
	string GetName();
	string Help();
};

