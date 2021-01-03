#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 2e5 + 50;

bool check[MAX_N];

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N;
		cin >> N;
		
		memset(check, false, sizeof(check));
		int ans = 0;
		for(int i = 0; i < N; i++) {
			int x;
			cin >> x;
			
			if(check[x] == false) check[x] = true, ans++;
			else if(check[x + 1] == false) check[x + 1] = true, ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
