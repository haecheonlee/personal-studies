/* editorial */

#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	for(int i = 1; i <= N; i++)
		if(a[i] >= 0)
			a[i] = -a[i] - 1;

	if(N & 1) {
		int mx = -1, idx = -1;
		for(int i = 1; i <= N; i++) 
			if(abs(a[i]) > mx) 
				mx = abs(a[i]), idx = i;
		a[idx] = -a[idx] - 1;
	}
	
	for(int i = 1; i <= N; i++) cout << a[i] << ' ';
	
	return 0;
}
