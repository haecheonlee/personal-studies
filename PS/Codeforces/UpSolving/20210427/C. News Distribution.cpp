#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 5e5 + 10;

int p[MAX_N];
int cnt[MAX_N];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]), y = Find(p[y]);
	if(x != y) p[y] = x;
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) p[i] = i;
	
	for(int i = 1; i <= M; i++) {
		int k; cin >> k;
		
		int x = -1;
		while(k--) {
			int y; cin >> y;
			if(x == -1) x = y;
			else Union(x, y);
		}
	}

	for(int i = 1; i <= N; i++) cnt[Find(i)]++;
	for(int i = 1; i <= N; i++) cout << cnt[Find(i)] << ' ';
	
	return 0;
}
