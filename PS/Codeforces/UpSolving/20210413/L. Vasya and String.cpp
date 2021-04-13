/* reference: Valkata.a.k.a.TheHacker */

#include <iostream>

using namespace std;

int N, K;

int go(string& s, char x) {
	int ans = 0;
	
	int j = 0, c = 0;
	for(int i = 0; i < N; i++) {
		if(s[i] != x) c++;
		while(j <= i && K < c) {
			if(s[j++] != x) c--;
		}
		
		if(i - j + 1 > ans)
			ans = i - j + 1;
	}
	
	return ans;
}

int main() {
	cin >> N >> K;
	string s; cin >> s;

	int p1 = go(s, 'a'), p2 = go(s, 'b');
	cout << max(p1, p2) << '\n';
	
	return 0;
}
