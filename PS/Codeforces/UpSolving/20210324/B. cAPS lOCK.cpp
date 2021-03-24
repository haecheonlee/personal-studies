#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	
	bool a = (s[0] & (1 << 5)), b = !(s[0] & (1 << 5));
	for(int i = 1; i < (int)s.size(); i++) {
		if((s[i] & (1 << 5))) a = 0, b = 0;
	}
	
	if(a || b) {
		for(int i = 0; i < (int)s.size(); i++) cout << (char)(s[i] ^ (1 << 5));
	} else {
		cout << s << '\n';
	}
	
	return 0;
}
