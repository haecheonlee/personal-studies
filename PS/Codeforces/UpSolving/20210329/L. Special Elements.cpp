#include <iostream>

using namespace std;

const int MAX_N = 8e3 + 10;

int a[MAX_N];
bool check[MAX_N]; 

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		check[i] = 0;
	}
	
	int ans = 0;
	for(int i = 3; i <= N; i++) {
		int L = 1, R = 1, sum = 0;
		while(L <= R) {
			if(R <= i - 1 && sum < a[i]) sum += a[R++];
			else sum -= a[L++];
			
			if(sum == a[i] && R - L >= 2) {
				check[i] = 1;
				ans++;
				break;
			}
		}
	}
	
	for(int i = N - 2; i >= 0; i--) {
		if(check[i]) continue;
		
		int L = N, R = N, sum = 0;
		while(L <= R) {
			if(L >= 1 && sum < a[i]) sum += a[L--];
			else sum -= a[R--];
			
			if(sum == a[i] && R - L >= 2) {
				check[i] = 1;
				ans++;
				break;
			}
		}
	}
	
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
