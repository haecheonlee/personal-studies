#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	
	bool flag = 1;
	int M = a[a.size() / 2];
	int diff = M - a[0];
	for(int i = 1; i < a.size(); i++) {
		if(a[i] == M) continue;
		if(diff != abs(M - a[i])) flag = 0;
	}
	cout << (flag ? "YES" : "NO") << '\n';
	
	return 0;
}
