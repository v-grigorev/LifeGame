#include "CommandLineHandler.h"
#include "Reader.h"
#include "Game.h"
#include "Writer.h"
#include "LifeException.h"
#include "StringUtilities.h"

void CommandLineHandler::Handle(int argc, char* argv[]) {
	bool name = false;
	bool tick = false; 
	string outFileName = "out.txt";
	vector<string> veccmd = ConvertToVecCmd(argc, argv);
	int tickCount = 0;
	int ind = InVector(veccmd, "-o");

	if (ind != -1) {
		if (argc < ind + 3) {
			throw LifeException("need output file name");
		}
		outFileName = veccmd[ind + 1];
		name = true;
	}

	ind = InVector(veccmd, "-i");
	if (ind != -1) {
		if (argc < ind + 3) {
			throw LifeException("need tick count");
		}
		if (StringUtilities::IsNumber(veccmd[ind + 1])) {
			tickCount = stoi(veccmd[ind + 1]);
			tick = true;
		}
		else {
			throw LifeException("argument not integer: " + veccmd[ind + 1]);
		}
	}

	if (!tick || !name) {
		for (auto s : veccmd) {
			if (s.find('=') != string::npos) {
				vector<string> vecs = SplitByEquality(s);
				if (vecs.size() != 2) {
					throw LifeException("invalid parameters count");
				}
				if (vecs[0] == "--iterations") {
					if (StringUtilities::IsNumber(vecs[1])) {
						tickCount = stoi(vecs[1]);
						tick = true;
					}
					else {
						throw LifeException("argument not integer: " + vecs[1]);
					}
				}
				else if (vecs[1] == "--output") {
					outFileName = vecs[1];
					tick = true;
				}
			}
		}
	}

	if (!tick) {
		throw LifeException("need tick count\nuse -i or --iteration=");
	}

	shared_ptr<Game> game = Reader::Read(veccmd[0]);
	game->HiddenTick(tickCount);
	Writer::Dump(game, outFileName);
}

vector<string> CommandLineHandler::ConvertToVecCmd(int argc, char* argv[]) {
	vector<string> out;
	for (int i = 1; i < argc; i++) {
		out.push_back(argv[i]);
	}
	return out;
}

int CommandLineHandler::InVector(const vector<string>& vec, const string s) {
	for (int i = 0; i < vec.size(); i++) {
		if (s == vec[i]) {
			return i;
		}
	}
	return -1;
}

vector<string> CommandLineHandler::SplitByEquality(const string& str) {
	vector<string> out;
	string buf_str;

	for (char elem : str) {
		if (elem == '=') {
			out.push_back(buf_str);
			buf_str = "";
		}
		else {
			buf_str += elem;
		}
	}
	if (buf_str != "")
		out.push_back(buf_str);
	return out;
}