#include <iostream>

#define sz(x) (int)x.size()

using namespace std;

int N;
int a[3][6];
bool check[1000], visited[3];

void go(int sum) {
	for(int i = 0; i < N; i++) {
		if(visited[i]) continue;
		visited[i] = 1;
		for(auto& x : a[i]) {
			check[sum * 10 + x] = 1;
			go(sum * 10 + x);
		}
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(auto& x : a[i]) {
			cin >> x;
			check[x] = 1;	
		}
	}
	
	for(int i = 0; i < N; i++) go(0);
	
	int ans = 0;
	for(int i = 1; i < 1000; i++) {
		if(!check[i]) break;
		ans = i;
	}
	cout << ans << '\n';

	return 0;
}
