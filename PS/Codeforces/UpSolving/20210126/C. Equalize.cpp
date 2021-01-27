#include <iostream>

using namespace std;

const int MAX_N = 1e6 + 1;

char a[MAX_N], b[MAX_N];

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) cin >> b[i];
 
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] != b[i]) {
			if(a[i] == b[i + 1] && b[i] == a[i + 1]) swap(a[i], a[i + 1]);
			else a[i] = b[i];
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
