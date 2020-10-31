#include <iostream>

using namespace std;

int N;
string ans = "";

bool check(int L, string& s) {
	for(int k=2; k<=L/2; k++) {
		for(int i=0; i<(int)s.size()-k; i++) {
			if(s.substr(i,k) == s.substr(i+k, k)) return false;
		}
	}
	
	return true;
}

void go(int L, string& s) {
	if(ans != "") return;
	if(L>=4 && !check(L, s)) return;
	if(L == N) {
		if(ans == "" || ans > s) ans = s;
		return;
	}
	
	for(int i=1; i<=3; i++) {
		char next = i + '0';
		if(next == s.back()) continue;
		
		s += next;
		go(L + 1, s);
		s.pop_back();
	}
}

int main() {
	cin>>N;
	
	string s = "";
	go(0, s);
	cout<<ans;
	
	return 0;
}
