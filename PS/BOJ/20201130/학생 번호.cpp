#include <iostream>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	string s[N];
	for(int i = 0; i < N; i++) cin >> s[i];
	
	int L = s[0].size();
	for(int k = L - 1; k >= 0; k--) {
		set<string> cnt;
		int pos = k;
		int LEN = L - k;
		
		for(int i = 0; i < N; i++) cnt.insert(s[i].substr(pos, LEN));

		if(cnt.size() == N) {
			cout << LEN << '\n';
			break;
		}
	}
	
	return 0;
}
