#include <iostream>

#define sz(x) (int)(x.size())

using namespace std;

int main() {
	string s;
	cin >> s;

	string ns = "";
	int pos = 0;
	for(int i = 0; i < sz(s); i++) {
		if(s[i] != 'a') ns += s[i];
		else pos = i + 1;
	}

	
	bool is_good = (sz(ns) / 2 <= sz(s) - pos);
	if((sz(ns) & 1)) is_good = false;	

	for(int i = 0; i < sz(ns) / 2; i++) {
		if(ns[i] != ns[sz(ns) / 2 + i]) { is_good = false; break; }
	}

	if(is_good) for(int i = 0; i < sz(s) - sz(ns) / 2; i++) cout << s[i];
	else cout << ":(";

	return 0;
}
