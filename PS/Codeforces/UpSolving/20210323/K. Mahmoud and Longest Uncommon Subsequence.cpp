#include <iostream>

using namespace std;

int main() {
	string s, ss; cin >> s >> ss;
	
	if(s == ss) {
		cout << -1 << '\n';
	} else {
		cout << max(s.size(), ss.size()) << '\n';
	}

	return 0;
}
