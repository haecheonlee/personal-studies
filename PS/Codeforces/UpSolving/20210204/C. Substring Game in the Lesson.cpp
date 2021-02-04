#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	
	char x = s[0];
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a') cout << "Mike" << '\n';
		else cout << (x < s[i] ? "Ann" : "Mike") << '\n';
		
		x = min(x, s[i]);
	}
	return 0;
}
