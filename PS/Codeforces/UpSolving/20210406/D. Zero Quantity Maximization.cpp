/* reference: editorial */

#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N], b[MAX_N];
map<pair<int,int>, int> m;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void norm(pair<int,int>& p) {
	if(p.first < 0) {
		p.first *= -1, p.second *= -1;
	} else if(p.first == 0 && p.second < 0) {
		p.second *= -1;
	}
	
	int d = gcd(abs(p.first), abs(p.second));
	p.first /= d;
	p.second /= d;
}

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) cin >> b[i];
	
	int ans = 0, cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(a[i] == 0) {
			if(b[i] == 0) cnt++;	
		} else {
			pair<int, int> p = make_pair(-b[i], a[i]);
			norm(p);
			m[p]++;
			ans = max(ans, m[p]);
		}
	}
	cout << ans + cnt << '\n';
	
	return 0;
}
