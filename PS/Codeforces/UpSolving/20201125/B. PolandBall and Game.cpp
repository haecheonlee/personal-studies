#include <iostream>
#include <map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	map<string,int> a, b;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		a[s]++;
	}
	
	int duplicate = 0;
	for(int i = 0; i < M; i++) {
		string s;
		cin >> s;
		
		b[s]++;
		if(a.find(s) != a.end()) duplicate++;
	}
	
	N -= duplicate, M -= duplicate;
	bool win = (duplicate & 1 ? 0 : 1);
	
	if(win) cout << (N > M ? "YES" : "NO"); 
	else cout << (N >= M ? "YES" : "NO");
	
	return 0;
}
