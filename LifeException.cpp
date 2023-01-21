#include "LifeException.h"

LifeException::LifeException(const string& msg) {
	message = msg;
}

LifeException::LifeException(const char* msg) : message(msg){
}

LifeException::LifeException(const char* msg, int err) : message(msg) {
	codeError = err;
}

int LifeException::GetCodError() const {
	return codeError;
}

const char* LifeException::what() const {
	return message.data();
}
