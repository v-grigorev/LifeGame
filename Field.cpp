#include "Field.h"
#include <utility>
#include <array>
#include <iostream>

Field::Field(int w, int h) : data(height), width(w), height(h) {
	for (auto& j : data) {
		j.resize(width, 0);
	}
}

void Field::PatternApply() {
	int centerH = height / 2;
	int centerW = width / 2;
	data[centerH][centerW + 1] = true;
	data[centerH - 1][centerW] = true;
	data[centerH + 1][centerW + 1] = true;
	data[centerH + 1][centerW] = true;
	data[centerH + 1][centerW - 1] = true;
}

const vector<vector<bool>>& Field::GetData() const {
	return data;
}

void Field::DoStep(Rules rules) {
	vector<vector<bool>> newData;
	newData.resize(height);

	for (auto& j : newData) {
		j.resize(width, 0);
	}

	array <bool, 9> birth = rules.GetBirth();
	array <bool, 9> survival = rules.GetSurvival();
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			int aliveCount = GetNumberAliveAround(h, w);
			if (data[h][w])
				newData[h][w] = survival[aliveCount];
			else
				newData[h][w] = birth[aliveCount];
		}
	}
	data = newData;
}

int Field::GetNumberAliveAround(int h, int w) const {
	int aliveCount = 0;
	for (auto& p : shift) {
		aliveCount += IsAlive(h + p.first, w + p.second);
	}
	return aliveCount;
}

bool Field::IsAlive(int h, int w) const {
	h = NormCord(h, height);
	w = NormCord(w, width);
	return data[h][w];
}

void Field::SetLife(const vector<pair<int, int>>& alive) {
	for (auto p : alive) {
		SetLife(p.first, p.second);
	}
}

void Field::SetLife(int h, int w) {
	h = NormCord(h, height);
	w = NormCord(w, width);
	data[h][w] = true;
}

int Field::NormCord(int cord, int limit) {
	return (cord + limit) % limit;
}

int Field::GetWidth() const {
	return width;
}

int Field::GetHeight() const {
	return height;
}

ostream& operator<<(ostream& o, const Field& field) {
	const vector <vector <bool>>& data = field.GetData();
	int height = field.GetHeight();
	int width = field.GetWidth();

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			if (data[h][w]) {
				o << to_string(h) << string(" ") << to_string(w) << endl;
			}
		}
	}
	return o;
}
