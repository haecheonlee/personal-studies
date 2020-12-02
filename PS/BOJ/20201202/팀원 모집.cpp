#include <iostream>

using namespace std;

const int MAX = 11;
const int INF = 1e9;

int N, M;
int a[MAX];

int go(int n, int sum) {
	if(n > M) return INF;
	if((sum + 1) == (1 << N)) return 0;
	
	return min(go(n + 1, sum), go(n + 1, (sum | a[n])) + 1);
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int j;
		cin >> j;
		
		int sum = 0;
		while(j--) {
			int k;
			cin >> k;
			k--;
			
			sum |= (1 << k);
		}
		a[i] = sum;
	}
	
	int ans = go(0,0);
	cout << (ans == INF ? -1 : ans);
	
	return 0;
}
