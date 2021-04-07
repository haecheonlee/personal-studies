#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 10;

int N, K, Q;
ll cnt[MAX_N], p[MAX_N];

int main() {
	fastio
   	cin >> N >> K;
	for(int i = 1; i <= K; i++) {
        	int x; cin >> x;
       		cnt[x]++;
	}

	p[0] = K;
    	for(int i = 0; i < N; i++) if(cnt[i]) for(int j = i; j < N; j += i) p[j] += cnt[i];
    	for(int i = 1; i < N; i++) p[i] += p[i - 1];
	cin >> Q;
	
	while(Q--) {
		int L, R; cin >> L >> R;
		cout << p[R] - (L > 0 ? p[L - 1] : 0) << '\n';
	}
    
	return 0;
}
