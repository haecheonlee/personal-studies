#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1e3 + 1;

bool check[MAX];

int main() {
	int N;
	cin >> N;
	
	vector<string> a(N);
	map<string,int> m;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		m[a[i]] = i;
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		
		int L = m[s];
		for(int j = 0; j < L; j++) {
			if(check[j]) continue;
			else { ans++; break; }
		}
		check[L] = true;
	}
	cout << ans << '\n';

	return 0;
}
