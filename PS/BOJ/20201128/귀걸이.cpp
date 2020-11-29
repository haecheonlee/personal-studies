#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int tc = 1;
	while(1) {
		int N;
		cin >> N;
		
		if(N == 0) break;

		map<string,bool> m;
		vector<string> a;
		cin.ignore();
		
		for(int i = 0; i < N; i++) {
			string s;
			getline(cin, s);

			a.push_back(s);
			m[s] = true;
		}
		
		for(int i = 0; i < 2 * N - 1; i++) {
			int idx;
			string type;
			cin >> idx >> type;
			
			m[a[idx - 1]] = !m[a[idx - 1]];
		}
		
		for(auto& p : m) {
			if(!p.second) {
				cout << tc++ << ' ' << p.first << '\n';
				break;	
			}
		}
	}

	return 0;
}
