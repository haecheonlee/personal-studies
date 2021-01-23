#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 2;

int a[MAX_N];
bool check[MAX_N];

int main() {
	int N;
	cin >> N;
	
	a[0] = 0, a[N + 1] = 1001;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	for(int i = 1; i <= N; i++) {
		if((a[i] - a[i - 1]) == 1 && (a[i + 1] - a[i]) == 1) check[i] = 1;
	}

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(check[i]) {
			int j = i;
			while(check[j + 1] && j <= N){ j++; }
			ans = max(ans, j - i + 1);
			i = max(i, j - 1);
		}	
	}
	cout << ans << '\n';

	return 0;
}
