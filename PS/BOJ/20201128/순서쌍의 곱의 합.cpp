#include <iostream>

using namespace std;

const int MAX = 1e4 + 1;

int a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		a[x]++;
	}
	
	long long ans = 0;
	for(int i = 1; i < MAX; i++) {
		if(a[i] >= 2) ans += 1LL * i * i * (1LL * (a[i] - 1) * a[i] / 2);
	}

	for(int i = 1; i < MAX; i++) {
		if(!a[i]) continue;
		for(int j = i + 1; j < MAX; j++) {
			if(!a[j]) continue;
			ans += 1LL * i * j * a[i] * a[j];
		}
	}
	cout << ans;
	
	return 0;
}
