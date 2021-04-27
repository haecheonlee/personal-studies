#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];
int p[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];

	int ans = -1;
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			int cnt = 0;
			if(i != 0) cnt++;
			if(j != 0) cnt++;
			
			a[1] += i, a[2] += j, p[1] += i, p[2] += j;
			int diff = a[1] - a[2];
			bool check = true;
			for(int k = 3; k <= N; k++) {
				bool flag = 0;
				for(int o = -1; o <= 1; o++) {
					if(a[k - 1] - (a[k] + o) == diff) {
						flag = 1;
						if(o != 0) cnt++;
						a[k] += o, p[k] += o;
						break;
					}
				}
				
				if(!flag) {
					check = 0;
					break;
				}
			}

			if(check) if(ans == -1 || ans > cnt) ans = cnt;
			for(int i = 1; i <= N; i++) {
				a[i] -= p[i];
				p[i] = 0;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
