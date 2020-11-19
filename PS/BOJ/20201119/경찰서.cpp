#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1e2 + 2;

int a[MAX];
bool check[MAX][MAX];
int p[MAX];
int g[MAX];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) {
		p[y] = x;	
	}
}

int main() {
	int N;
	cin >> N;

	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			char x;
			cin >> x;
			
			if(x == '1') check[i][j] = true;
		}	
	}
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(i == j) continue;
				if(check[i][j] == false) check[i][j] = (check[i][k] && check[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= N; i++) p[i] = i;
	
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			if(check[i][j] && check[j][i]) Union(i, j);
		}
	}
	
	memset(g, -1, sizeof(g));
	for(int i = 1; i <= N; i++) {
		int gn = Find(p[i]);
		if(g[gn] == -1 || g[gn] > a[i]) g[gn] = a[i];
	}
	
	int ans = 0;
	for(int i = 1; i < MAX; i++) {
		if(g[i] == -1) continue;
		ans += g[i];
	}
	cout << ans << '\n';

	return 0;
}
