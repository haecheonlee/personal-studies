#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5 + 10;

int l1[MAX], r1[MAX], l2[MAX], r2[MAX];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> l1[i] >> r1[i];
	sort(l1, l1 + N); sort(r1, r1 + N);
	
	int M; cin >> M;
	for(int i = 0; i < M; i++) cin >> l2[i] >> r2[i];
	sort(l2, l2 + M); sort(r2, r2 + M);
	
	int ans = 0;
	for(int i = 0; i < N; i++) if(r1[i] < l2[M - 1]) ans = max(ans, l2[M - 1] - r1[i]);
	for(int i = 0; i < M; i++) if(r2[i] < l1[N - 1]) ans = max(ans, l1[N - 1] - r2[i]);
	cout << ans << '\n';

	return 0;
}
