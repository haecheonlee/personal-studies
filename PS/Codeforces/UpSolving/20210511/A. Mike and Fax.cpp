#include <iostream>

using namespace std;

bool is_pal(string s) {
	int N = s.size();
	for(int i = 0; i < N / 2; i++) {
		if(s[i] != s[N - 1 - i]) return false;
	}
	return true;
}

int main() {
	string s; cin >> s;
	int K; cin >> K;

	int N = s.size();
	if(N % K != 0) {
		cout << "NO" << '\n';
	} else {
		int L = N / K;
		bool flag = 1;
		for(int i = 0; i < N; i += L) if(is_pal(s.substr(i, L)) == false) flag = 0;
		cout << (flag ? "YES" : "NO") << '\n';
	}

	return 0;
}
