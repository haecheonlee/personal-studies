#include <iostream>

using namespace std;

int main(){
	string s; cin >> s;

	int one = 0;
	for(auto& c : s) if(c == '1') one++;

	int i = 0, zero = 0;
	while(i < (int)s.size() && (s[i] == '0' || s[i] == '1')) {
		zero += (s[i] == '0');
		i++;
	}
	
	string ans = string(zero, '0') + string(one, '1');
	for(int k = i; k < (int)s.size(); k++) if(s[k] != '1') ans += s[k];
	cout << ans << '\n';
	
	return 0;
}
