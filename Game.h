#pragma once
#include <string>
#include "Field.h"
#include "Rules.h"

using namespace std;

class Game {
public:
	Game();

	Game(const string& name, const string& strRules, const vector <pair <int, int>>& alive);
	const Field& GetField() const;
	const Rules& GetRules() const;
	const string& GetName() const;
	void Start();
	void Tick(int count);
	void HiddenTick(int count);
	void Show();
private:
	const int widht = 30;
	const int height = 30;
	Field field; 
	const Rules rules;
	const string name;
};

