#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1e2 + 1;
const int MAX_H = 5e4 + 1;
const int INF = 1e9;

int p[MAX_N], c[MAX_N];
int d[MAX_H];

int main() {
	int N, H;
	cin >> N >> H;
	
	for(int i = 0; i < N; i++) cin >> p[i] >> c[i];

	fill(d, d + MAX_H, INF);
	d[0] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 1; j <= H; j++) {
			if(j - p[i] >= 0) d[j] = min(d[j], d[j - p[i]] + c[i]);
			else d[j] = min(d[j], c[i]);
		}
	}
	cout << d[H] << '\n';
	
	return 0;
}
