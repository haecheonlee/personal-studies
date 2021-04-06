#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ll N, X, Y; cin >> N >> X >> Y;
	string s; cin >> s;
	
	vector<int> p;
	for(int i = 0; i < N; i++) {
		if(s[i] == '0') {
			while(i < N && s[i + 1] != '1') i++;
			p.push_back(i);
		}
	}
	ll K = p.size();
	cout << min(K * Y, max(0LL, K - 1) * X + Y);
	
	return 0;
}
