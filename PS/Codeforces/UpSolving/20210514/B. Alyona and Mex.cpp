#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	a[0] = 1;
	for(int i = 1; i < N; i++) {
		if(a[i] == a[i - 1]) continue;
		if(a[i] > a[i - 1]) a[i] = a[i - 1] + 1;
	}
	cout << a[N - 1] + 1 << '\n';
	
	return 0;
}
