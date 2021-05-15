#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 5e3 + 10;

int a[MAX_N];
bool check[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	

	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(a[i] < a[j] && !check[j]) {
				check[j] = true;
				break;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < N; i++) if(!check[i]) ans++;
	cout << ans << '\n';

	return 0;
}
