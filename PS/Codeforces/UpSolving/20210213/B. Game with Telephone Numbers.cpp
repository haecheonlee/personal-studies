/* editorial */

#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	int cnt1 = (N - 11) / 2;
	int cnt2 = cnt1;
	
	string res = "";
	for(int i = 0; i < N; i++) {
		if(s[i] == '8') {
			if(cnt1 > 0) --cnt1;
			else res += s[i];
		} else {
			if(cnt2 > 0) --cnt2;
			else res += s[i];
		}
	}
	
	if(res[0] == '8') cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}
