#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	int L = 0, R = N - 1;
	string ans;
	vector<int> p;
	
	bool changed = 1;
	while(changed && L <= R) {
		changed = 0;
		
		if(a[L] < a[R]) {
			if(p.empty() || p.back() < a[L]) {
				p.push_back(a[L]);
				ans += "L";
				L++;
				
				changed = 1;
			} else if(p.back() < a[R]){
				p.push_back(a[R]);
				ans += "R";
				R--;
				
				changed = 1;
			}
		} else {
			if(p.empty() || p.back() < a[R]) {
				p.push_back(a[R]);
				ans += "R";
				R--;
				
				changed = 1;
			} else if(p.back() < a[L]) {
				p.push_back(a[L]);
				ans += "L";
				L++;
				
				changed = 1;
			}
		}
	}

	cout << ans.size() << '\n';
	cout << ans << '\n';
	
	return 0;
}
