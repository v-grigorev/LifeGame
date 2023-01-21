#pragma once
#include <string>
#include <vector>
#include <array>

using namespace std;

class Rules {
public:
	Rules(const string& strRules);

	array <bool, 9> GetBirth() const;
	array <bool, 9> GetSurvival() const;
	const string& GetRulesString() const;
private:
	array <bool, 9> birth;
	array <bool, 9> survival;
	string strRulesDump;
};

ostream& operator<<(ostream& o, const Rules& rules);
