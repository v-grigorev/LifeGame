#include "CommandFactory.h"
#include "start.h"
#include "Load.h"
#include "Tick.h"
#include "Dump.h"
#include "Show.h"
#include "LifeException.h"
#include <iostream>

CommandFactory::CommandFactory() {
    vector <shared_ptr<Command>> command_vec = {
    make_shared<Start>(),
    make_shared<Load>(),
    make_shared<Tick>(),
    make_shared<Dump>(),
    make_shared<Show>()
    };

    for (auto com : command_vec) {
        factory_map[com->GetName()] = com;
    }

}

shared_ptr<Command> CommandFactory::GetCommand(const string& commandName) {
    if (factory_map.count(commandName))
        return factory_map[commandName];
    throw LifeException("command not found");
}

void CommandFactory::Help() {
    for (auto j : factory_map) {
        cout << j.second->GetName() << endl;
        cout << j.second->Help();
        cout << "------------------" << endl;
    }
}
