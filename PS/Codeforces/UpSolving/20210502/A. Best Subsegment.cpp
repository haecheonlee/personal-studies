#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	
	int mx = -1;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] > mx) mx = a[i];
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(a[i] == mx) {
			int cnt = 0;
			while(i <= N && a[i] == mx) cnt++, i++;
			ans = max(ans, cnt);
		}
	}
	cout << ans << '\n';
	
	return 0;
}
