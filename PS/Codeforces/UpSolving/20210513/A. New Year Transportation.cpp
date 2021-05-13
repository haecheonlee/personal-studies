#include <iostream>

using namespace std;

const int MAX_N = 3e4 + 10;

int a[MAX_N];
bool check[MAX_N];

int main() {
	int N, T; cin >> N >> T;
	for(int i = 1; i <= N - 1; i++) cin >> a[i];

	int now = 1;
	while(now <= N) {
		if(now <= N) check[now] = true;
		if(now >= N) break;
		now += a[now];
	}
	cout << (check[T] ? "YES" : "NO") << '\n';
	
	return 0;
}
