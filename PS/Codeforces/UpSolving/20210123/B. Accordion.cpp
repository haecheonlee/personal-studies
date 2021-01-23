/* reference: editorial */

#include <iostream>
#include <algorithm>

using namespace std;

void rem(string& s, const string &c) {
	auto p = s.find(c);
	if(p == string::npos) {
		cout << -1 << '\n';
		exit(0);
	}
	s.erase(0, p + 1);
}

int main() {
	string s;
	cin >> s;

	rem(s, "[");
	rem(s, ":");
	reverse(s.begin(), s.end());
	rem(s, "]");
	rem(s, ":");
	
	cout << count(s.begin(), s.end(), '|') + 4 << '\n';

	return 0;
}
