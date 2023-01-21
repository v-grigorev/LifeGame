#include "Start.h"
#include "Reader.h"
#include "LifeException.h"
#include <memory>

shared_ptr<Game> Start::DoCommand(shared_ptr<Game> game, const vector<string>& argv) {
	if (!game) {
		throw LifeException("universe not opened\nuse load command");
	}
	game->Start();
	return game;
}

string Start::GetName() {
	return "start";
}

string Start::Help() {
	return "show universe frame by frame.\n";
}