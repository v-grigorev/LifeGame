#pragma once
#include <string>
#include <memory>
#include "Game.h"

using namespace std;

class Writer {
public:
	void static Dump(shared_ptr<const Game> game, const string& fileName);
};

