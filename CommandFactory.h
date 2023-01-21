#pragma once
#include "Command.h"
#include <string>
#include <memory>
#include <map>

using namespace std;

class CommandFactory {
public:
	CommandFactory();
	shared_ptr<Command> GetCommand(const string&);
	void Help();
private:
	map <string, shared_ptr<Command>> factory_map;
};

