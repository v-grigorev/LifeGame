#include "Reader.h"
#include "LifeException.h"
#include "StringUtilities.h"
#include <fstream>

using namespace std;

shared_ptr<Game> Reader::Read(const string& fileName) {
    ifstream fin(fileName);

    if (!fin.is_open()) {
        throw LifeException("file not open");
    }

    string line;
    getline(fin, line);

    if (line.substr(0, 2) != "#N") {
        throw LifeException("invalid universe format");
    }
    string universe_name = line.substr(3);

    getline(fin, line);
    if (line.substr(0, 2) != "#R") {
        throw LifeException("invalid universe format");
    }

    string str_rules = line.substr(3);

    vector <pair <int, int>> alive;

    while (getline(fin, line)) {
        int sep_ind = line.find(' ');
        if (sep_ind == string::npos) {
            throw LifeException("invalid coord format: not enough 2 cords");
        }
        if (!StringUtilities::IsNumber(line.substr(0, sep_ind)) || !StringUtilities::IsNumber(line.substr(sep_ind))) {
            throw LifeException("coord is not a integer: " + line);
        }

        int w = stoi(line.substr(0, sep_ind));
        int h = stoi(line.substr(sep_ind));
        pair <int, int> p = make_pair(w, h);
        alive.push_back(p);
    }

    return make_shared<Game>(universe_name, str_rules, alive);
}
