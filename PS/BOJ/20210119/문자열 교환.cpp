/* reference: YunGoon's idea */

#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	s = s + s;
	
	int N = (int)s.size();
	int a = 0;
	for(int i = 0; i < N / 2; i++) if(s[i] == 'a') a++;
	
	int b = 0;
	for(int i = 0; i < a; i++) if(s[i] == 'b') b++;
	
	int ans = b;
	for(int i = a; i < N; i++) {
		if(s[i - a] == 'b') b--;
		if(s[i] == 'b') b++;
		
		ans = min(ans, b);
	}
	cout << ans << '\n';

	return 0;
}
