#include <iostream>

using namespace std;

int main() {
	int N;
	string S;
	
	cin >> N >> S;
	
	int ans = 0;
	for(int i = 0; i < N - 1; i++) {
		if(S[i] == 'E' && S[i + 1] == 'W') ans++;
	}
	cout << ans << '\n';
	
	return 0;
}
