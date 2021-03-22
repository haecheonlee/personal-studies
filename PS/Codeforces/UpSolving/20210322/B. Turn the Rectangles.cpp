#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e5 + 10;

pii a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a[i].first >> a[i].second;
		if(a[i].first < a[i].second) swap(a[i].first, a[i].second);	
	}
	
	int now = 1e9 + 1;
	for(int i = 0; i < N; i++) {
		if(a[i].first <= now) now = a[i].first;
		else if(a[i].second <= now) now = a[i].second;
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';

	return 0;
}
