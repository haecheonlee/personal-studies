#include <iostream>

using namespace std;

int main() {
	int N, x, y; cin >> N >> x >> y;
	string s; cin >> s;
	
	int ans = s[N - y - 1] == '0';
	for(int i = N - x; i < N - y - 1; i++) if(s[i] == '1') ans++;
	for(int i = N - y; i < N; i++) if(s[i] == '1') ans++;
	cout << ans << '\n';

	return 0;
}
