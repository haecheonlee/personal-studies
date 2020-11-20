#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main() {
	int N;
	long long K;
	
	cin >> N >> K;

	int a[N];
	int mx = -1;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	deque<int> q;
	int wins[N] {0};
	for(int i = 0; i < N; i++) q.push_back(i);

	while(!q.empty()) {
		int p = q.front(); q.pop_front();
		int pp = q.front(); q.pop_front();
		
		if(a[p] == mx) {
			cout << a[p];
			return 0;
		} else if(a[pp] == mx) {
			cout << a[pp];
			return 0;
		}
		
		if(a[p] > a[pp]) {
			q.push_front(p);
			q.push_back(pp);
			wins[p]++;
			
			if(wins[p] == K) {
				cout << a[p];
				return 0;
			}
		} else {
			q.push_front(pp);
			q.push_back(p);
			wins[pp]++;
			
			if(wins[pp] == K) {
				cout << a[pp];
				return 0;
			}
		}
	}
	
	return 0;
}
