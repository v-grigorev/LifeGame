#include "Dump.h"
#include "Writer.h"
#include "LifeException.h"

shared_ptr<Game> Dump::DoCommand(shared_ptr<Game> game, const vector<string>& argv) {
    if (!game) {
        throw LifeException("universe not opened\nuse load command");
    }

    if (argv.size() == 1) {
        throw LifeException("need file name");
    }

    if (argv.size() == 2) {
        Writer::Dump(game, argv[1]);
        return game;
    }
    throw LifeException("too much arguments");
}

string Dump::GetName() {
    return "dump";
}

string Dump::Help() {
    return "Save universe in file.\n1 argument: output file name\n";
}
