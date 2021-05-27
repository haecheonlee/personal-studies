#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> a(N / 2);
	for(int i = 0; i < N / 2; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	int k = 1;
	int os = 0, es = 0;
	for(auto& x : a) {
		os += abs(x - k);
		es += abs(x - (k + 1));
		k += 2;
	}
	cout << min(os, es) << '\n';
	
	return 0;
}
