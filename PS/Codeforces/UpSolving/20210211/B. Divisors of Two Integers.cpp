/* editorial */

#include <iostream>
#include <set>

using namespace std;

int main() {
	int N; cin >> N;
	
	multiset<int> a;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		a.insert(x);
	}

	int mx = *prev(a.end());
	for(int i = 1; i <= mx; i++) {
		if(mx % i == 0) a.erase(a.find(i));
	}
	cout << mx << ' ' << *prev(a.end()) << '\n';
	
	return 0;
}
