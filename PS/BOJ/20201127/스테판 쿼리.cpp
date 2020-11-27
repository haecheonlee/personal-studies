#include <iostream>

using namespace std;

int win(int a, int b, int c){
	if(a == 1 && b == 3) return 1;
	if(a == 2 && b == 1) return 1;
	if(a == 3 && b == 2) return 1;
	if(a == b && c == 2) return 1;

	return 2;
}

int main() {
	int N;
	cin >> N;
	
	int a[N], b[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) cin >> b[i];
	
	int ans = 0, winning = 0, p = -1;
	for(int i = 0; i < N; i++) {
		int w = win(a[i], b[i], p);
		
		if(p != w) p = w, winning = 1;
		else if(p == w) winning++;

		ans = max(ans, winning);
	}
	cout << ans;

	return 0;
}
