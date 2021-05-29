#include <iostream>

using namespace std;

int main() {
	long long N, M; cin >> N >> M;
	if(N < M) swap(N, M);
	
	long long ans = 0;
	for(int i = 1; i <= N; i++) ans += ((i + M) / 5 - (i / 5));
	cout << ans << '\n';
	
	return 0;
}
