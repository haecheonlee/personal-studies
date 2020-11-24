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

	double a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);

	for(int i = 0; i < N - 1; i++) a[N - 1] += a[i] / 2;
	cout << fixed << setprecision(5) << a[N - 1] << '\n';

	return 0;
}
