#include <iostream>

using namespace std;

int main() {
	int N, M;
	while(cin >> N >> M) {
		int ans = 0;
		
		for(int i = N; i <= M; i++) {
			int sum = 0;
			bool is_good = true;
			string s = to_string(i);
			
			for(int k = 0; k < (int)s.size() && is_good; k++) {
				int c = s[k] - '0';
				if(sum & (1 << c)) is_good = false;
				sum |= (1 << c);
			}
			
			if(is_good) ans++;
		}
		
		cout << ans << '\n';
	}

	return 0;
}
