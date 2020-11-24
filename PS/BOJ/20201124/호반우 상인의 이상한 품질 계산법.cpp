#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int N;
	cin >> N;

	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);

	for(int i = N - 1; i > (N - 1) / 2; i--) a[i] = a[N - 1 - i] = a[i];

	int ans = 0;
	for(int i = 0; i < N; i++) ans += a[i];
	cout << ans << '\n';

	return 0;
}
