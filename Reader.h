#pragma once
#include "Game.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Reader {
public:
	static shared_ptr<Game> Read(const string& fileName);
};

