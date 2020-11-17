/* reference: http://serjudging.vanb.org/wp-content/uploads/Cousins_artur.java */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

int main() {
	int N, K;
	while(cin >> N >> K) {
		if(N == 0 && K == 0) break;
		
		int NK = -1;
		int a[N];
		
		for(int i = 0; i < N; i++) {
			cin >> a[i];
			if(a[i] == K) NK = i;
		}
		
		int p[N];
		int H = p[0] = -1;
		for(int i = 1; i < N; i++) {
			if(a[i] != a[i - 1] + 1) H++;
			p[i] = H;
		}
		
		int ans = 0;
		if(p[NK] != -1) {
			for(int i = 1; i < N; i++) {
				if(p[p[i]] == p[p[NK]] && p[i] != p[NK]) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
