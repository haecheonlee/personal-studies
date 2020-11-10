#include <iostream>
#include <set>

#define sz(x) (int)(x.size())

using namespace std;

int main() {
	int N;
	cin >> N;
	
	multiset<string> a;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;

		a.insert(s);
	}

	multiset<string> b;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;

		auto it = a.find(s);
		if(it != a.end()) a.erase(it);
		else b.insert(s);
	}

	int ans = 0;
	auto ita = a.begin(), itb = b.begin();
	for(int i = 0; i < sz(a); i++) {
		auto s1 = *ita;
		auto s2 = *itb;

		for(int j = 0; j < sz(s1); j++) {
			if(s1[j] != s2[j]) ans++;
		}

		ita++, itb++;
	}
	cout << ans;

	return 0;
}
