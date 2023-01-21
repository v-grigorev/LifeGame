#pragma once
#include <vector>
#include <string>
#include <memory>

using namespace std;

class CommandLineHandler {
public:
	static void Handle(int argc, char* argv[]);
private:
	static vector<string> ConvertToVecCmd(int argc, char* argv[]);
	static int InVector(const vector<string>& vec, const string s);
	static vector<string> SplitByEquality(const string& str);
};

