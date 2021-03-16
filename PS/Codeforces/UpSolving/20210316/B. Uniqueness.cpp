#include <iostream>
#include <map>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];

	int ans = N - 1;
	map<int,int> m;
	for(int i = 0; i < N; i++) {
		bool isPrefixValid = 1;
		for(int j = 0; j < i; j++) {
			m[a[j]]++;
			
			if(m[a[j]] == 2) {
				isPrefixValid = 0;
				break;
			}
		}
		
		int idx = N;
		for(int j = N - 1; j >= i; j--) {
			m[a[j]]++;
			
			if(m[a[j]] == 1) idx = j;
			else break;
		}
		
		if(isPrefixValid) 
			ans = min(ans, idx - i);
			
		m.clear();
	}
	cout << ans << '\n';

	return 0;
}
