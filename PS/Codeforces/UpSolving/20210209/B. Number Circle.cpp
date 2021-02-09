#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	for(int i = N - 2; i >= 1; i--) swap(a[i], a[i - 1]);

	bool is_good = 1;
	for(int i = N - 1; i >= 0 && is_good; i--) {
		int sum = 0;
		if(i == 0) sum = a[i + 1] + a[N - 1];
		else if(i == N - 1) sum = a[i - 1] + a[0];
		else sum = a[i - 1] + a[i + 1];
		if(sum <= a[i]) is_good = 0;
	}

	if(is_good) {
		cout << "YES" << '\n';
		for(int i = N - 1; i >= 0; i--) cout << a[i] << ' ';
	} else {
		cout << "NO" << '\n';
	}
	
	return 0;
}
