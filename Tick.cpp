#include "Tick.h"
#include "Game.h"
#include "LifeException.h"
#include "StringUtilities.h"
#include <string>

using namespace std;

shared_ptr<Game> Tick::DoCommand(shared_ptr<Game> game, const vector<string>& argv) {
    if (!game) {
        throw LifeException("universe not opened\nuse load command");
    }

    if (argv.size() == 1) {
        throw LifeException("not enough arguments");
    }

    if (!StringUtilities::IsNumber(argv[1])) {
        throw LifeException("argument not integer: " + argv[1]);
    }

    if (argv.size() == 2) {
        if (StringUtilities::IsNumber(argv[1])) {
            game->Tick(stoi(argv[1]));
            return game;
        }
        else {
            throw LifeException("argument not integer: " + argv[1]);
        }
    }

    if (argv[2] == "-h") {
        game->HiddenTick(stoi(argv[1]));
        return game;
    }
    throw LifeException("too much arguments");
}

string Tick::GetName() {
    return "tick";
}

string Tick::Help() {
    return "do several step.\n1 argument tick count\n1 optional argument: -h do not print universe to console\n";
}