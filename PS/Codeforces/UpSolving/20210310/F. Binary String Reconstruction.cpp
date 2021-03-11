#include <iostream>

using namespace std;

void solve() {
	int n0, n1, n2; cin >> n0 >> n1 >> n2;
	
	string ans = "";
	if(n1 == 0) {
		if(n2 == 0) for(int i = 0; i < n0 + 1; i++) ans += "0";
		if(n0 == 0) for(int i = 0; i < n2 + 1; i++) ans += "1";
	} else if(n1 == 1) {
		for(int i = 0; i < n0 + 1; i++) ans += "0";
		for(int i = 0; i < n2 + 1; i++) ans += "1";
	} else {
		for(int i = 0; i < n1; i++) {
			if(i & 1) ans += "1";
			else ans += "0";
		}
		
		if(n1 & 1) {
			for(int i = 0; i < n0; i++) ans += "0";
			for(int i = 0; i < n2 + 1; i++) ans += "1";
		} else {
			for(int i = 0; i < n2; i++) ans += "1";
			for(int i = 0; i < n0 + 1; i++) ans += "0";
		}
	}
	
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
