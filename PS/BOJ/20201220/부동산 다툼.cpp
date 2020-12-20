#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

bool check[(1<<20) + 1];

int main() {
	fastio
	
	int N, Q;
	cin >> N >> Q;
	
	while(Q--) {
		int x;
		cin >> x;
		
		bool already = check[x];
		check[x] = true;
		
		// going up
		int X = x, ans = x;
		while(X) {
			X /= 2;
			if(check[X]) ans = X;
		}
		
		cout << (ans == x && !already ? 0 : ans) << '\n';
	}

	return 0;
}
