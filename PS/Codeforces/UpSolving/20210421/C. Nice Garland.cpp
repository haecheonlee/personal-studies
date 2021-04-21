#include <iostream>

using namespace std;

string k[] {
	"RGB", "RBG",
	"BRG", "BGR",
	"GRB", "GBR"
};

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	int idx = -1, ans = 2e5 + 10;
	for(int i = 0; i < 6; i++) {
		int cnt = 0;
		for(int j = 0; j < N; j++) {
			if(k[i][j % 3] != s[j]) cnt++;
		}
		
		if(ans > cnt) {
			ans = cnt;
			idx = i;
		}
	}
	
	cout << ans << '\n';
	for(int i = 0; i < N; i++) cout << k[idx][i % 3];
	
	return 0;
}
