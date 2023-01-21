#pragma once
#include <exception>
#include <string>

using namespace std;

class LifeException : public exception {
public:
	LifeException(const string&);
	LifeException(const char* msg);
	LifeException(const char* msg, int err);
	int GetCodError() const;
	const char* what() const;
private:
	string message;
	int codeError = 0;
};

