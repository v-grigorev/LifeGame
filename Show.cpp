#include "Show.h"

shared_ptr<Game> Show::DoCommand(shared_ptr<Game> game, const vector<string>& argv) {
    if (!game) {
        puts("universe not opened\nuse load command");
    }
    game->Show();
    return game;
}

string Show::GetName() {
    return "show";
}

string Show::Help() {
    return "show universe.\n";
}