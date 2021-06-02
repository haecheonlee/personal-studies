#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	
	vector<int> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];
	string s; cin >> s;
	
	for(int i = 0; i < N - 1; i++) {
		if(s[i] == '1') {
			int j = i;
			while(j + 1 < N - 1 && s[j + 1] == '1') j++;
			sort(a.begin() + i, a.begin() + j + 2);
			i = j;
		}
	}
	
	bool flag = 1;
	for(int i = 0; i < N - 1; i++) if(a[i] > a[i + 1]) flag = 0;
	cout << (flag ? "YES" : "NO") << '\n';
	
	return 0;
}
