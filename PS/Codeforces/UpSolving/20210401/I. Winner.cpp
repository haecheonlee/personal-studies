#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 1e3 + 10;

map<string, int> m, m2;
string name[MAX_N];
int score[MAX_N];

int main() {
	int N; cin >> N;
	
	for(int i = 1; i <= N; i++) {
		cin >> name[i] >> score[i];
		m[name[i]] += score[i];
	}
	
	int mx = 0;
	for(auto mm : m) mx = max(mx, mm.second);
	for(int i = 1; i <= N; i++) {
		m2[name[i]] += score[i];
		if(m[name[i]] == mx && m2[name[i]] >= mx) {
			cout << name[i] << '\n';
			break;
		}	
	}

	return 0;
}
