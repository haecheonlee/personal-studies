#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int N = s.size();
	
	for(int i = 0; i < N; i++) {
		if(s[i] == s[i + 1]) {
			char x;
			for(int k = 0; k < 26; k++) {
				if(s[i] != k + 'a' && s[i + 2] != k + 'a') {
					s[i + 1] = 'a' + k;
					break;
				}
			}
		}
	}
	cout << s << '\n';

	return 0;
}
