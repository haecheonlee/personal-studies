#include <iostream>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int a[N];
	set<int> b;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		b.insert(a[i]);
	}
	
	int ans = 0;
	for(auto& it : b) {
		int v = -1, L = 0;
		for(int i = 0; i < N; i++) {
			if(a[i] == it) continue;
			if(v == a[i]) L++;
			else v = a[i], L = 1;
			
			ans = max(ans, L);
		}
		
	}
	
	cout << ans;
	return 0;
}
