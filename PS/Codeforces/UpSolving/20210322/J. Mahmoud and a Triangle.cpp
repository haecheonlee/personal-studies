#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];	
	sort(a, a + N);
	
	for(int i = N - 3; i >= 0; i--) {
		if(a[i] + a[i + 1] > a[i + 2]) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	
	return 0;
}
