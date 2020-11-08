#include <iostream>

using namespace std;

const int MAX = 1e2;

string a[MAX];

int main() {
	int N, H, W;
	cin >> N >> H >> W;
	
	for(int i = 0; i < H; i++) cin >> a[i];
	
	string ans(N,'?');
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N * W; j += W) {
			char now = '?';
			for(int k = j; k < j + W; k++) {
				if(a[i][k] != '?') now = a[i][k]; 
			}
			if(now != '?') ans[j / W] = now;
		}
	}
	
	for(int i = 0; i < N; i++) cout << ans[i];

	return 0;
}
