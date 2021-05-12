#include <iostream>
#include <set>

using namespace std;

int main() {
	int N; cin >> N;
	string s[N]; for(int i = 0; i < N; i++) cin >> s[i];
	
	set<string> st;
	for(int i = N - 1; i >= 0; i--) {
		if(st.find(s[i]) == st.end()) cout << s[i] << '\n';
		st.insert(s[i]);
	}
	
	return 0;
}
