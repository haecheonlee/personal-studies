#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int L = 0, R = 0;
	while(a[0] == a[R]) R++;
	
	int ans = 0;
	while(L < N && R < N) {
		if(a[L] < a[R]) ans++, L++;
		R++;
	}
	cout << ans << '\n';
	
	return 0;
}
