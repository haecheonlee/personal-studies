#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int N = (int)s.size();
	
	if(N < 26) {
		cout << -1 << '\n';
		return 0;
	}

	int now = 0;
	for(int i = 0; i < N && now < 26; i++) {
		if(s[i] <= 'a' + now) s[i] = ('a' + now), now++;
	}
	
	if(now == 26) cout << s << '\n';
	else cout << -1 << '\n';

	return 0;
}
