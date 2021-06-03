#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;

	int ans = 0;
	for(int i = 0; i < N - 1; i++) {
		if(s[i] == s[i + 1]) {
			string x = "RGB";
			
			if(i + 2 < N) {
				if(x.find(s[i + 2]) != string::npos)
					x.erase(x.find(s[i + 2]), 1);
			}
			
			if(x.find(s[i]) != string::npos) 
				x.erase(x.find(s[i]), 1);
			
			s[i + 1] = x[0];
			ans++;
		}
	}
	cout << ans << '\n' << s << '\n';

	return 0;
}
