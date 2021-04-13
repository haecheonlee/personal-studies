#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 10;

int a[MAX_N], pos[MAX_N];

int main() {
	int N, Q; cin >> N >> Q;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(pos[a[i]] == 0) pos[a[i]] = i;
	}
	
	for(int i = 1; i <= Q; i++) {
		int x; cin >> x;
		cout << pos[x] << ' ';
		for(int j = 1; j <= 50; j++) {
			if(pos[j] != -1 && pos[j] < pos[x]) {
				pos[j]++;
			}
		}
		pos[x] = 1;
	}

	return 0;
}
