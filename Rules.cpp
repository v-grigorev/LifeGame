#include "Rules.h"
#include <fstream>

array <bool, 9> Rules::GetBirth() const {
	return birth;
}

array <bool, 9> Rules::GetSurvival() const {
	return survival;
}

const string& Rules::GetRulesString() const {
	return strRulesDump;
}

void StrRulesParse(const string& strRules, array <bool, 9>& rule) {
	memset(rule.data(), false, 9);
	for (char c : strRules) {
		if (c == '/') {
			break;
		}
		if (c < '0' && c > '8') {
			throw exception("invalid rules");
		}
		rule[c - '0'] = true;
	}
}

Rules::Rules(const string& strRules) {
	if (strRules[0] != 'B')
		throw exception("invalid rules format");
	string strBirth = strRules.substr(1);
	StrRulesParse(strBirth, birth);

	int sep_ind = strRules.find('/');

	if (strRules[sep_ind + 1] != 'S')
		throw exception("invalid rules format");
	string strSurvival = strRules.substr(sep_ind + 2);
	StrRulesParse(strSurvival, survival);
	strRulesDump = strRules;
}

ostream& operator<<(ostream& o, const Rules& rules) {
	o << rules.GetRulesString();
	return o;
}
