#include "CmdPrinter.h"
#include <iostream>
#include <Windows.h>
	
using namespace std;

void CmdPrinter::print(const Field& field) {
	int width = field.GetWidth();
	int height = field.GetHeight();
	const vector <vector <bool>>& data = field.GetData();
	puts("\033[H");
	int outCount = (2 * width + 1) * height + 1;
	char* out = new char[outCount];
	int writtenCount = 0;

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			out[writtenCount] = (data[h][w] ? 254 : '.');
			writtenCount++;
			out[writtenCount] = ' ';
			writtenCount++;
		}
		out[writtenCount] = '\n';
		writtenCount++;
	}

	out[writtenCount] = '\0';
	fwrite(out, 1, outCount, stdout);
	delete [] out; 
}

void CmdPrinter::ConsoleConfigure() {
	HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD consoleMode;
	GetConsoleMode(handleOut, &consoleMode);
	consoleMode |= 0x0004;
	consoleMode |= 0x0008;
	SetConsoleMode(handleOut, consoleMode);
}
