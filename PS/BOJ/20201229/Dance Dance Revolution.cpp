#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e5 + 1;

int idx;
int a[MAX];
int d[MAX][5][5];

bool is_adj(int now, int next) {
	if(now == 1) return next == 2 || next == 4;
	else if(now == 2) return next == 1 || next == 3;
	else if(now == 3) return next == 2 || next == 4;
	else return next == 1 || next == 3;
}

int go(int i, int l, int r) {
	if(a[i] == 0) return 0;

	int& ret = d[i][l][r];
	if(ret != -1) return ret;
	ret = 1e9;
	
	// move left
	if(l == 0) ret = min(ret, go(i + 1, a[i], r) + 2);
	else if(l == a[i]) ret = min(ret, go(i + 1, a[i], r) + 1);
	else if(is_adj(l, a[i])) ret = min(ret, go(i + 1, a[i], r) + 3);
	else ret = min(ret, go(i + 1, a[i], r) + 4);
	
	// move right
	if(r == 0) ret = min(ret, go(i + 1, l, a[i]) + 2);
	else if(r == a[i]) ret = min(ret, go(i + 1, l, a[i]) + 1);
	else if(is_adj(r, a[i])) ret = min(ret, go(i + 1, l, a[i]) + 3);
	else ret = min(ret, go(i + 1, l, a[i]) + 4);
	
	return ret;
}

int main() {
	while(cin >> a[idx++]);

	memset(d, -1, sizeof(d));
	cout << go(0, 0, 0);
	
	return 0;
}
