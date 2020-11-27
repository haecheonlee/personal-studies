#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4 * 1e5 + 1;
bool check[MAX];

int main() {
	int N, K;
	cin >> N >> K;
	
	string s;
	cin >> s;
	
	vector<int> p[26];
	for(int i = 0; i < (int)s.size(); i++) p[s[i] - 'a'].push_back(i);
	
	for(int i = 0; i < 26 && K; i++) {
		for(int j = 0; j < p[i].size() && K; j++) {
			check[p[i][j]] = true;
			K--;
		}
	}
	
	for(int i = 0; i < N; i++) if(!check[i]) cout << s[i];

	return 0;
}
