#include <iostream>
#include <set>

using namespace std;

int main() {
	int N; cin >> N;
	
	multiset<int> s;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	
	int ans = 0, now = *s.begin();
	s.erase(s.begin());
	while(!s.empty()) {
		auto it = s.lower_bound(now + 1);
		if(it != s.end()) {
			now = *it;
			s.erase(it);
			ans++;
		} else {
			if(!s.empty()) {
				it = s.begin();
				now = *it;
				s.erase(it);
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}
