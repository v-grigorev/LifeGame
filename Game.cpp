#include "Game.h"
#include "CmdPrinter.h"
#include <Windows.h>

using namespace std;

Game::Game() : field(widht, height), rules("B3/S23"), name("sampleUniverse") {
	CmdPrinter::ConsoleConfigure();
	field.PatternApply();
}

Game::Game(const string& newName, const string& strRules, 
		   const vector <pair <int, int>>& alive) : 
	       field(widht, height), rules(strRules), name(newName)
{
	CmdPrinter::ConsoleConfigure();
	field.SetLife(alive);
}

const Field& Game::GetField() const {
	return field;
}

const Rules& Game::GetRules() const {
	return rules;	
}

const string& Game::GetName() const {
	return name;
}

bool SleepWithBreak(int time, int breakButton) {
	int i = 0;
	while (i < time) {
		if (GetKeyState(breakButton) < 0) {
			return false;
		}
		Sleep(10);
		i += 10;
	}
	return true;
}

void Game::Start() {
	do {
		CmdPrinter::print(field);
		field.DoStep(rules);
	} while (SleepWithBreak(250, 0x43));
	puts("\033[2J");
}

void Game::Tick(int count) {
	for (int i = 0; i < count; i++) {
		field.DoStep(rules);
	}
	CmdPrinter::print(field);
}

void Game::HiddenTick(int count) {
	for (int i = 0; i < count; i++) {
		field.DoStep(rules);
	}
}

void Game::Show() {
	CmdPrinter::print(field);
}




