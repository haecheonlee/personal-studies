#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int N;
	cin >> N;
 
	vector<int> a[N + 1];
	for(int i = 1; i <= 2 * N; i++) {
		int x;
		cin >> x;
 
		a[x].push_back(i);
	}
 
	long long ans = 0;
	int p = 1, pp = 1;
	for(int i = 1; i <= N; i++) {
		int d1 = abs(p - a[i][0]) + abs(pp - a[i][1]);
		int d2 = abs(p - a[i][1]) + abs(pp - a[i][0]);
 
		if(d1 <= d2) ans += d1, p = a[i][0], pp = a[i][1];
		else ans += d2, p = a[i][1], pp = a[i][0];
	}
	cout << ans;
 
	return 0;
}
