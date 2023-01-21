#pragma once
#include "Game.h"
#include <vector>
#include <string>
#include <memory>
#include <map>

using namespace std;

class Command {
public:
	virtual shared_ptr<Game> DoCommand(shared_ptr<Game> game, const vector<string>& argv) = 0;
	virtual string GetName() = 0;
	virtual string Help() = 0;
};

