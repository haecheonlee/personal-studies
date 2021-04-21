/* reference: ediotorial */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K; cin >> N >> K;
	string s; cin >> s;

	vector<int> p(N);
	for(int i = 1; i < N; i++) {
		int j = p[i - 1];
		while(j > 0 && s[j] != s[i]) j = p[j - 1];
		
		if(s[i] == s[j]) j++;
		p[i] = j;
	}

	int L = N - p[N - 1];
	for(int i = 0; i < K - 1; i++) cout << s.substr(0, L);
	cout << s << '\n';

	return 0;
}
