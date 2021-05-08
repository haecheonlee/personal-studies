#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	
	int t = 0, c = 1e9;
	for(int x = 1; x <= 100; x++) {
		int cost = 0;
		for(int i = 1; i <= N; i++) {
			if(a[i] == x) continue;
			if(a[i] < x) cost += abs(a[i] - (x - 1));
			else if(a[i] > x) cost += abs(a[i] - (x + 1));
		}
		if(c > cost) t = x, c = cost;
	}
	cout << t << ' ' << c << '\n';
	
	
	return 0;
}
