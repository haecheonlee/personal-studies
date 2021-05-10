#include <iostream>

using namespace std;

int a, b, x;

void construct(char s, char ss, int small, int big) {
	string ans = "";
	int cnt = 0;
	for(int i = 0; i < big; i++) {
		ans += ss;
		if(x >= 2) {
			if(x == 2) for(int j = cnt; j < small; j++) ans += s;
			else ans += s, cnt++;
			x -= 2;
		}
	}

	if(x) for(int i = cnt; i < small; i++) ans += s;
	cout << ans << '\n';
}

int main() {
	cin >> a >> b >> x;
	
	if(x == 1) {
		for(int i = 0; i < a; i++) cout << 0;
		for(int i = 0; i < b; i++) cout << 1;
	} else {
		if(a < b) construct('0', '1', a, b);
		else construct('1', '0', b, a);
	}
	
	return 0;
}
