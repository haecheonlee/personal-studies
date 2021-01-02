#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 1;

int N;
int a[MAX_N];
vector<int> p;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--) {
		cin >> N;
		
		vector<int> p(N + 1, 0);
		for(int i = 1; i <= N; i++) {
			cin >> a[i];
			p[i] = p[i - 1] + a[i];
		}
		
		int ans = 0, sum = 0;
		for(int i = 1, j; i <= N; i++) {
			ans += a[i];
		
			int pos = 1, sum = ans;
			bool is_good = true;
			while(pos < N && is_good) {
				pos = lower_bound(p.begin(), p.end(), sum) - p.begin();
				if(p[pos] != sum) { is_good = false; break; }
				sum += ans;
			}
			
			if(is_good) break;
		}
		cout << ans << '\n';
	}

	return 0;
}
