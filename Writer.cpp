#include "Writer.h"
#include "Rules.h"
#include "Field.h"
#include <fstream>

using namespace std;

void Writer::Dump(shared_ptr<const Game> game, const string& fileName) {
	ofstream out;
	if (fileName.find('.') == string::npos) {
		out.open(fileName + ".txt", ios::out);
	}
	else {
		out.open(fileName, ios::out);
	}

	
	out << "#N " << game->GetName() << endl;
	out << "#R " << game->GetRules() << endl;
	out << game->GetField() << endl;
}