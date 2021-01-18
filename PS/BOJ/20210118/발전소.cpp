#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 16;
const int INF = 1e9;

int N, P;
int a[MAX][MAX];
int d[MAX][1 << MAX];

int go(int n, int state) {
	if(n >= P) return 0;

	int& ret = d[n][state];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int i = 0; i < N; i++) {
		if((state & (1 << i)) == 0) {
			int mn = -1;
			
			for(int k = 0; k < N; k++) {
				if(i == k) continue;
				
				if(state & (1 << k)) {
					if(mn == -1 || mn > a[k][i]) mn = a[k][i];
				}
			}
			
			if(mn != -1) ret = min(ret, go(n + 1, state | (1 << i)) + mn);
		}
	}
	
	return ret;
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) 
			cin >> a[i][j];
	
	int cnt = 0, state = 0;
	for(int i = 0; i < N; i++) {
		char x;
		cin >> x;
		
		if(x == 'Y') cnt++, state |= (1 << i);
	}
	
	cin >> P;
	memset(d, -1, sizeof(d));
	int ans = go(cnt, state);
	
	cout << (ans == INF ? -1 : ans) << '\n';
	
	return 0;
}
