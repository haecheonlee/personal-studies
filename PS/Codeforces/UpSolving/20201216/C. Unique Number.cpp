#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;

int ans[51];
bool check[10] { false };

void go(int a, int sum, int x) {
	if(sum > x) return;
	if(sum == x) {
		ans[x] = min(ans[x], a);
		return;
	}
	
	for(int i = 1; i <= 9; i++) {
		if(check[i]) continue;
		check[i] = 1;
		go(a * 10 + i, sum + i, x);
		check[i] = 0;
	}
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int x;
		cin >> x;
		
		memset(check, false, sizeof(check));
	
		if(ans[x] == 0) {
			ans[x] = INF;
			go(0, 0, x);
			cout << (ans[x] == INF ? -1 : ans[x]) << '\n';			
		} else {
			cout << (ans[x] == INF ? -1 : ans[x]) << '\n';
		}
	}

	return 0;
}
