#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 20;

int N;
int a[MAX_N][MAX_N];
int d[(1 << MAX_N) + 1];

int go(int s, int n) {
	if(n == N) return 0;
	
	int& ret = d[s];
	if(ret != -1) return ret;
	ret = 1e9;
	
	for(int i = 0; i < N; i++) {
		if(s & (1 << i)) continue;
		int ns = s | (1 << i);
		
		ret = min(ret, go(ns, n + 1) + a[i][n]);
	}

	return ret;	
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) 
			cin >> a[i][j];
	
	memset(d, -1, sizeof(d));
	cout << go(0, 0);
	
	return 0;
}
