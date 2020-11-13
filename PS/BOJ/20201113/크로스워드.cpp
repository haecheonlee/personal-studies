#include <iostream>
#include <set>

#define sz(s) (int)(s.size())

using namespace std;

const int MAX = 2e1 + 1;

char a[MAX][MAX];
set<string> ans;

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin >> a[i][j];
	}

	for(int i = 0; i < N; i++) {
		string s = "";
		for(int j = 0; j < M; j++) {
			if(a[i][j] == '#') {
				if(sz(s) > 1) ans.insert(s);
				s = "";
			} else {
 				s += a[i][j];
			}
		}

		if(sz(s) > 1) ans.insert(s);
	}

	for(int j = 0; j < M; j++) {
		string s = "";
		for(int i = 0; i < N; i++) {
			if(a[i][j] == '#') {
				if(sz(s) > 1) ans.insert(s);
				s = "";
			} else {
				s += a[i][j];
			}
		}
		if(sz(s) > 1) ans.insert(s);
	}

	cout << *ans.begin();

	return 0;
}
