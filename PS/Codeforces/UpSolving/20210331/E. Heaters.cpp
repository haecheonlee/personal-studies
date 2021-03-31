/* refernec: https://www.youtube.com/watch?v=njhde81wvBk&ab_channel=AnmolGera */

#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 10;

int a[MAX_N], b[MAX_N];

int main() {
	int N, R; cin >> N >> R;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		
		if(a[i] == 1) {
			// to left
			for(int j = i; j >= max(0, i - R + 1); j--) b[j]++;
			for(int j = i + 1; j <= min(N - 1, i + R - 1); j++) b[j]++;
		}
	}
	
	bool flag = 1;
	for(int i = 0; i < N && flag; i++) {
		if(!b[i]) flag = 0;
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] == 1) {
			bool flag2 = 0;
			for(int j = i; j >= max(0, i - R + 1); j--) {
				if(b[j] <= 1) {
					flag2 = 1;
					break;
				}
			}
			
			for(int j = i; j <= min(N - 1, i + R - 1); j++) {
				if(b[j] <= 1) {
					flag2 = 1;
					break;
				}
			}
			
			if(flag2) {
				ans++;
			} else {
				for(int j = i; j >= max(0, i - R + 1); j--) b[j]--;
				for(int j = i + 1; j <= min(N - 1, i + R - 1); j++) b[j]--;
			}
		}
	}
	cout << (flag ? ans : -1) << '\n';
	
	return 0;
}
