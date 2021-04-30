#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 10;

int a[MAX_N], b[MAX_N];
bool check[MAX_N][1000];

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	for(int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		for(int k = 0; b[i] + a[i] * k < 1000; k++) 
			check[i][b[i] + a[i] * k] = 1;
	}
	
	int ans = 0;
	for(int k = 0; k < 1000; k++) {
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			if(check[i][k]) s[i] = ('1' + '0') - s[i];
			if(s[i] == '1') cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	
	return 0;
}
