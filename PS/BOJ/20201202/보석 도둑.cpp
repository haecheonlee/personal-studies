#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ll K;
	cin >> K;
	
	vector<ll> ans;
	for(ll i = 2; i * i <= K; i++) {
		if(K % i == 0) {
			ans.push_back(i);
			K /= i;
			i = 1;
		}
	}

	ans.push_back(K);

	cout << (int)ans.size() << '\n';
	for(auto& x: ans) cout << x << ' ';

	return 0;
}
