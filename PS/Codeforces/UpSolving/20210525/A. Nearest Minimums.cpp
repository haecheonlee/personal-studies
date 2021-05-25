#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	
	int x = 1e9 + 1;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		x = min(x, a[i]);
	}
	
	vector<int> p;
	for(int i = 1; i <= N; i++) if(a[i] == x) p.push_back(i);
	
	int ans = 1e9;
	for(int i = 1; i < p.size(); i++) ans = min(ans, p[i] - p[i - 1]);
	cout << ans << '\n';

	return 0;
}
