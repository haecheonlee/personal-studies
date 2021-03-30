/* reference: https://codeforces.com/contest/609/submission/14895448 */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

ll a[MAX_N];

int main() {
	int N; cin >> N;
	
	ll sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];	
	}
	
	ll mx, mn;
	mx = mn = sum / N;
	mx++;
	
	ll L = 0, R = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] < mn) L += (mn - a[i]);
		else if(a[i] > mx) R += (a[i] - mx);
	}
	cout << max(L, R) << '\n';

	return 0;
}
