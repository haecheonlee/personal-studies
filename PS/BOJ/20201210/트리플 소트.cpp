#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
	fastio
	
	int N;
	cin >> N;
	
	vector<int> a(N + 1);
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	bool ans = true;
	for(int i = 1; i <= N; i++) if((a[i]&1) != (i&1)) ans = false;
	
	cout << (ans ? "YES" : "NO");
	
	return 0;
}
