#pragma once
#include <array>
#include <vector>
#include "Rules.h"

using namespace std;

class Field {
public:
	Field(int w, int h);

	const vector <vector <bool>>& GetData() const;
	int GetNumberAliveAround(int h, int w) const;
	void SetLife(const vector <pair <int, int>>& alive);
	void PatternApply();
	void DoStep(Rules rules);
	int GetWidth() const;
	int GetHeight() const;

private:
	const int width;
	const int height;

	bool IsAlive(int h, int w) const;
	void SetLife(int h, int w);
	static int NormCord(int cord, int limit);
	vector <vector <bool>> data;
	const array <pair <int, int>, 8> shift = {
		make_pair(-1, -1),
		make_pair(-1, 0),
		make_pair(-1, 1),
		make_pair(0, -1),
		make_pair(0, 1),
		make_pair(1, -1),
		make_pair(1, 0),
		make_pair(1, 1),
	};
};

ostream& operator<<(ostream& o, const Field& field);
