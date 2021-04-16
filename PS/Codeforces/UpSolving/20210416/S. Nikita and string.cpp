#include <iostream>

using namespace std;

const int MAX_N = 5e3 + 10;

int a[MAX_N], b[MAX_N];

int main() {
	string s; cin >> s;
	int N = s.size();
	
	for(int i = 0; i < N; i++) {
		a[i] = (s[i] == 'a');
		b[i] = (s[i] == 'b');
		
		if(i > 0) a[i] += a[i - 1], b[i] += b[i - 1];
	}

	int ans = 0;
	for(int i = 0; i < N; i++) 
		for(int j = N; j >= i; j--) 
			ans = max(ans, a[i - 1] + b[j - 1] - b[i - 1] + a[N - 1] - a[j - 1]);
	cout << ans << '\n';
	
	return 0;
}
