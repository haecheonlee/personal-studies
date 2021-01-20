#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N;
		cin >> N;
		
		int a[N];
		for(int i = 0; i < N; i++) cin >> a[i];
		sort(a, a + N);
		
		int x = 0, y = 0;
		for(int i = 0; i < N; i++) {
			if(x == a[i]) x++;
			else if(y == a[i]) y++;
		}
		cout << x + y << '\n';
	}

	return 0;
}
