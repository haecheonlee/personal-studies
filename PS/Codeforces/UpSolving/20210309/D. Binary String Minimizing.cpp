#include <iostream>
#include <vector>

using namespace std;

void solve() {
	long long N, K; cin >> N >> K;
	string s; cin >> s;
	
	vector<int> zero;
	for(int i = 0; i < N; i++)
		if(s[i] == '0') 
			zero.push_back(i);
			
	long long pos = 0;
	for(int i = 0; i < (int)zero.size() && K; i++) {
		if(zero[i] != pos) {
			long long move = min(K, abs(zero[i] - pos));
			K -= move;
			swap(s[zero[i]], s[zero[i] - move]);
		}
		
		pos++;
	}
	cout << s << '\n';
}

int main() {
	int T; cin >>T;
	while(T--) solve();
	
	return 0;
}
