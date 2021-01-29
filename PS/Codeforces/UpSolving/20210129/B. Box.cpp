#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 2;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	
	set<int> s;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		s.insert(i);
	}

	vector<int> ans;
	for(int i = 1; i <= N; i++) {
		if(a[i] < a[i - 1]) {
			cout << -1 << '\n';
			return;	
		}
		
		if(a[i] > a[i - 1]) {
			ans.push_back(a[i]);
			s.erase(a[i]);
		} else {
			if((*s.begin()) >= a[i]) {
				cout << -1 << '\n';
				return;
			} else {
				ans.push_back(*s.begin());
				s.erase(s.begin());
			}
		}
	}
	
	for(auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();
	
	return 0;
}
