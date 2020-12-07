#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int p[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int a[N];
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		p[a[i]]++;
	}
	
	for(int i = 0; i < N; i++) {
		int x = a[i];
		int ans = 0;
		for(int k = 1; k * k <= x; k++) {
			if(x % k == 0) {
				int nx = x / k;
				if(nx == k) {
					ans += p[nx];
					if(nx == a[i]) ans--;
				} else {
					ans += p[nx] + p[k];	
					if(nx == a[i]) ans--;
					if(k == a[i]) ans--;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
