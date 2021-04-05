#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5e4 + 10;

int a[MAX_N];
bool check[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	for(int i = 0; i < N; i++) {
		if(a[i] - 1 >= 1 && !check[a[i] - 1]) check[a[i] - 1] = 1;
		else if(!check[a[i]]) check[a[i]] = 1;
		else if(!check[a[i] + 1]) check[a[i] + 1] = 1;
	}

	int ans = 0;
	for(int i = 1; i < MAX_N; i++) ans += check[i];
	cout << ans << '\n';
	
	return 0;
}
