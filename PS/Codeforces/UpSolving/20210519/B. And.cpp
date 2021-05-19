#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];
int cnt1[MAX_N], cnt2[MAX_N];

int main() {
	int N, x; cin >> N >> x;
	for(int i = 1; i <= N; i++) {
		cin >> a[i]; cnt1[a[i]]++;
		if(cnt1[a[i]] >= 2) {
			cout << 0 << '\n';
			return 0;
		}
	}
	
	int ans = MAX_N;
	for(int i = 1; i <= N; i++) {
		int k = a[i] & x; cnt2[k]++;
		
		if(cnt1[k] - (a[i] == k) >= 1) ans = min(ans, 1);
		else if(cnt2[k] >= 2) ans = min(ans, 2);
	}
	cout << (ans == MAX_N ? -1 : ans) << '\n';
	
	return 0;
}
