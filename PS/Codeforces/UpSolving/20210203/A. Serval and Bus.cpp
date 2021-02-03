#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int MAX_T = 2e5 + 1;

int a[MAX_T];

int main() {
	int N, T; cin >> N >> T;
	
	for(int i = 1; i <= N; i++) {
		int s, d; cin >> s >> d;
		for(int k = s; k < MAX_T; k += d) {
			if(a[k] == 0) a[k] = i;
		}
	}
	
	for(int k = T; k < MAX_T; k++) {
		if(a[k] == 0) continue;
		cout << a[k] << '\n';
		break;
	}

	return 0;
}
